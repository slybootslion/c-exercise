#include <pcap/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

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

void recv_data(int new_sockfd) {
	char buf[1024];
	struct sockaddr_in client_addr;
	socklen_t len = sizeof client_addr;

	while (1) {
		memset(buf, 0, sizeof buf);
		long n = recvfrom(new_sockfd, buf, sizeof buf, 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to sendto");
			exit(EXIT_FAILURE);
		}
		printf_client_info(&client_addr, buf);
		if (strncmp(buf, "quit", 4) == 0)
			break;
	}
	close(new_sockfd);
	exit(EXIT_FAILURE);
}

void sig_handler(int signum) {
	waitpid(-1, NULL, WNOHANG);
	printf("recv singnum = %d zombie\n", signum);
}

int user_login(const char* ip, const char* port) {
	char buf[20];
	struct sockaddr_in client_addr;
	socklen_t len = sizeof client_addr;
	int sockfd, new_sockfd;

	sockfd = init_socket(ip, port);

	while (1) {
		memset(buf, 0, sizeof buf);
		long n = recvfrom(sockfd, buf, sizeof buf, 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to sendto");
			exit(EXIT_FAILURE);
		}
		printf("key = %s\n", buf);

		unsigned char login_flag = strncmp(buf, "root", 4) == 0 ? LOGIN_SUCCESS : LOGIN_FAILURE;

		// 密钥正确
		if (login_flag == LOGIN_SUCCESS) {
			if (fork() == 0) {
				close(sockfd);
				new_sockfd = init_socket(ip, "0");
				sendto(new_sockfd, &login_flag, sizeof(login_flag), 0, (struct sockaddr*)&client_addr, len);
				break;
			}
		} else {
			sendto(sockfd, &login_flag, sizeof login_flag, 0, (struct sockaddr*)&client_addr, len);
		}
	}

	return new_sockfd;
}

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (signal(SIGCHLD, sig_handler) == SIG_ERR) {
		perror("Fail to single\n");
		return -1;
	}

	int sockfd = user_login(argv[1], argv[2]);

	recv_data(sockfd);
	return 0;
}
