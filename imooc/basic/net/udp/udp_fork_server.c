#include <pcap/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "udp_recv.h"

#define LOGIN_SUCCESS 1
#define LOGIN_FAILURE 0

void printf_client_info(struct sockaddr_in* addr, char* buf) {
	printf("===\n");
	printf("Recv from IP = %s\n", inet_ntoa(addr->sin_addr));
	printf("Recv from PORT = %hu\n", ntohs(addr->sin_port));
	printf("Recv data: %s\n", buf);
}

int init_socket(const char* ip, const char* port) {
	struct sockaddr_in my_addr;
	socklen_t len = sizeof my_addr;

	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		exit(EXIT_FAILURE);
	}

	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = inet_addr(ip);
	my_addr.sin_port = htons(atoi(port));

	if (bind(sockfd, (struct sockaddr*)&my_addr, len) < 0) {
		perror("Fail to bind");
		exit(EXIT_FAILURE);
	}

	return sockfd;
}

void recv_data(int sockfd) {
	long n;
	char buf[1024];
	struct sockaddr_in client_addr;
	unsigned int len = sizeof client_addr;

	while (1) {
		memset(buf, 0, sizeof(buf));
		n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to recvfrom");
			exit(EXIT_FAILURE);
		}

		printf("===\n");
		printf("Recv from IP = %s\n", inet_ntoa(client_addr.sin_addr));
		printf("Recv from PORT = %hu\n", ntohs(client_addr.sin_port));
		printf("Recv %ld bytes: %s\n", n, buf);

		if (strncmp(buf, "quit", 4) == 0)
			break;
	}
}

void udp_recv_ex(const char* ip, const char* port) {
	// 通过socket创建文件描述符
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in my_addr;

	// 填充自己 ip+port
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = inet_addr(ip);
	my_addr.sin_port = htons(atoi(port));

	// 把ip、
	int len = sizeof(my_addr);
	if (bind(sockfd, (struct sockaddr*)&my_addr, len) < 0) {
		perror("Fail to bind");
		exit(EXIT_FAILURE);
	}
	printf("wait recv data!\n");

	// 接收数据
	recv_data(sockfd);

	// 关闭文件描述符
	close(sockfd);
}

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	udp_recv_ex(argv[1], argv[2]);
	return 0;
}
