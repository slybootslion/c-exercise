#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define LOGIN_SUCCESS 1
#define LOGIN_FAILURE 0

void printf_client_info(struct sockaddr_in* addr, char* buf) {
	printf("===");
	printf("Recv from IP = %s\n", inet_ntoa(addr->sin_addr));
	printf("Recv from PORT = %hu\n", ntohs(addr->sin_port));
	printf("Recv data: %s\n", buf);
}

typedef struct
{
	char* ip;
	unsigned char flag;
	struct sockaddr_in* peer_addr;
} thread_type;

int init_socket(const char* ip, const char* port) {
	struct sockaddr_in my_addr;
	socklen_t len = sizeof my_addr;

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		exit(EXIT_FAILURE);
	}

	memset(&my_addr, 0, sizeof my_addr);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(atoi(port));
	my_addr.sin_addr.s_addr = inet_addr(ip);

	if (bind(sockfd, (struct sockaddr*)&my_addr, len) < 0) {
		perror("Fail to bind");
		return -1;
	}

	return sockfd;
}

void recv_data(int sockfd) {
	char buf[1024];
	struct sockaddr_in client_addr;
	socklen_t len = sizeof client_addr;
	while (1) {
		memset(buf, 0, sizeof buf);
		long n = recvfrom(sockfd, buf, sizeof buf, 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to recvfrom");
			exit(EXIT_FAILURE);
		}
		printf_client_info(&client_addr, buf);
		if (strncmp(buf, "quit", 4) == 0)
			break;
	}
	close(sockfd);
}

void* message_thread(void* arg) {
	thread_type* packet = (thread_type*)arg;
	char* ip = packet->ip;
	unsigned char login_flag = packet->flag;
	struct sockaddr_in* addr = packet->peer_addr;

	int new_sockfd = init_socket(ip, "0");
	sendto(new_sockfd, &login_flag, sizeof login_flag, 0, (struct sockaddr*)addr, sizeof(struct sockaddr_in));
	recv_data(new_sockfd);
	pthread_exit(NULL);
}

void user_login(const char* ip, const char* port) {
	char buf[1024] = { 0 };
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	unsigned char login_flag;
	int sockfd;
	thread_type packet;
	pthread_t tid;
	//1.创建套接字,获得用户数据
	sockfd = init_socket(ip, port);

	while (1) {
		memset(buf, 0, sizeof buf);
		int n = (int)recvfrom(sockfd, buf, sizeof buf, 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to recvfrom");
			exit(EXIT_FAILURE);
		}
		printf("key = %s\n", buf);

		login_flag = strncmp(buf, "root", 4) == 0 ? LOGIN_SUCCESS : LOGIN_FAILURE;

		if (login_flag == LOGIN_SUCCESS) {
			packet.ip = (char*)ip;
			packet.flag = login_flag;
			packet.peer_addr = &client_addr;
			// 创建子线程，子线程准备接受当前用户数据，主线程继续接受新用户的密钥
			pthread_create(&tid, NULL, message_thread, (void*)&packet);
		} else {
			sendto(sockfd, &login_flag, sizeof(login_flag), 0, (struct sockaddr*)&client_addr, len);
		}
		pthread_detach(tid);
	}
}

int main(int argc, const char* argv[]) {
	int sockfd;
	unsigned char login_flag;
	if (argc < 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	user_login(argv[1], argv[2]);
	return 0;
}
