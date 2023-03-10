#include <pthread.h>
#include "../server/linklist.h"

void* recv_message(void* arg) {
	int sockfd = *(int*)arg;
	char buf[1024];
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);

	while (1) {
		memset(buf, 0, sizeof(buf));
		long n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to recvfrom");
			exit(EXIT_FAILURE);
		}
		if (strncmp(buf, "quit", 4) == 0)
			break;
		printf("recv %ld bytes: %s\n", n, buf);
	}
	exit(EXIT_SUCCESS);
}

void send_data(int sockfd, struct sockaddr_in* peer_addr, int len) {
	char buf[1024];
	while (1) {
		putchar('>');
		memset(buf, 0, sizeof buf);
		fgets(buf, sizeof buf, stdin);
		buf[strlen(buf) - 1] = '\0';

		if (strncmp(buf, "quit", 4) == 0)
			break;
		long n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr*)peer_addr, len);
		if (n < 0) {
			perror("Fail to sendto");
			exit(EXIT_FAILURE);
		}
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
		return -1;
	}

	struct sockaddr_in peer_addr;
	int len = sizeof peer_addr;
	memset(&peer_addr, 0, sizeof peer_addr);
	peer_addr.sin_family = AF_INET;
	peer_addr.sin_addr.s_addr = inet_addr(argv[1]);
	peer_addr.sin_port = htons(atoi(argv[2]));

	pthread_t tid;
	int ret = pthread_create(&tid, NULL, recv_message, (void*)&sockfd);
	if (ret != 0) {
		fprintf(stderr, "Fail to pthread_create: %s\n", strerror(ret));
		exit(EXIT_FAILURE);
	}

	send_data(sockfd, &peer_addr, len);
	close(sockfd);
	return 0;
}
