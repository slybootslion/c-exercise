#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "udp_send.h"

#define LOGIN_SUCCESS 1
#define LOGIN_FAILURE 0

void send_data(int sockfd, struct sockaddr_in* addr, int len) {
	long n;
	char buf[1024];
	while (1) {
		putchar('>');
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf) - 1] = '\0';

		n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)addr, len);
		if (n < 0) {
			perror("fail to sendto");
			exit(EXIT_FAILURE);
		}

		if (strncmp(buf, "quit", 4) == 0)
			break;
	}
}

void udp_send_ex(const char* ip, const char* port) {
	// 通过socket创建文件描述符
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in peer_addr;

	// 填充服务器 ip+port
	memset(&peer_addr, 0, sizeof(peer_addr));
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_addr.s_addr = inet_addr(ip);
	peer_addr.sin_port = htons(atoi(port));

	// 发送数据
	send_data(sockfd, &peer_addr, sizeof(peer_addr));

	// 关闭文件描述符
	close(sockfd);
}

void send_message(int sockfd, struct sockaddr_in* addr, unsigned int addr_len) {
	char buf[1024];
	while (1) {
		printf("Input: ");
		memset(buf, 0, sizeof buf);
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf) - 1] = '\0';

		long n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)addr, addr_len);
		if (n < 0) {
			perror("Fail to sendto");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buf, "quit", 4) == 0)
			break;
	}
}

void user_login(int sockfd, struct sockaddr_in* addr, struct sockaddr_in* new_addr, long len) {
	char buf[1024];
	unsigned char flag = LOGIN_FAILURE;
	while (1) {
		putchar('>');
		memset(buf, 0, sizeof buf);
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf) - 1] = '\0';

		long n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)addr, len);
		if (n < 0) {
			perror("Fail to sendto");
			exit(EXIT_FAILURE);
		}
		recvfrom(sockfd, &flag, sizeof flag, 0, (struct sockaddr*)new_addr, (unsigned int*)&len);
		if (flag == LOGIN_SUCCESS)
			break;
		printf("key is invalid\n");
	}
}

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in peer_addr, server_addr;
	socklen_t len = sizeof peer_addr;
	memset(&peer_addr, 0, sizeof peer_addr);
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_addr.s_addr = inet_addr(argv[1]);
	peer_addr.sin_port = htons(atoi(argv[2]));

	memset(&server_addr, 0, sizeof server_addr);
	user_login(sockfd, &peer_addr, &server_addr, len);

	send_message(sockfd, &server_addr, len);

	close(sockfd);
	return 0;
}
