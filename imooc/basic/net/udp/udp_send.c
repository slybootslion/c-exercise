#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "udp_send.h"

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
