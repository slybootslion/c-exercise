#include "linklist.h"

int init_socket(const char* ip, const char* port) {
	struct sockaddr_in my_addr;
	int len = sizeof my_addr;
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sockfd < 0) {
		perror("Fail to socket!");
		return -1;
	}
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(atoi(port));
	my_addr.sin_addr.s_addr = inet_addr(ip);
	if (bind(sockfd, (struct sockaddr*)&my_addr, len) < 0) {
		perror("Fail to bind\n");
		return -1;
	}
	printf("wait recv data!\n");
	return sockfd;
}

int recv_data(int sockfd, linknode_t* head) {
	struct sockaddr_in client_addr;
	socklen_t len = sizeof client_addr;
	char buf[1024];

	while (1) {
		memset(buf, 0, sizeof buf);
		long n = recvfrom(sockfd, buf, sizeof buf, 0, (struct sockaddr*)&client_addr, &len);
		if (n < 0) {
			perror("Fail to recvfrom\n");
			exit(EXIT_FAILURE);
		}
		if (!find_linklist(head, &client_addr))
			insert_head_linklist(head, client_addr);
		broadcast_message(sockfd, head, buf, (int)n);
	}
}

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int sockfd = init_socket(argv[1], argv[2]);
	linknode_t* head = create_empty_linklist();
	recv_data(sockfd, head);
	close(sockfd);
	return 0;
}
