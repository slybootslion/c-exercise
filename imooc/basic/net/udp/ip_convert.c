#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include "ip_convert.h"

void ip_convert_first(const char* ip) {
	in_addr_t net_addr = inet_addr(ip);
	if (net_addr == INADDR_NONE) {
		perror("Fail to inet_addr");
		exit(EXIT_FAILURE);
	}
	printf("net_addr = %#x\n", net_addr);
}

void ip_convert_second(const char* ip) {
	struct in_addr net_addr;
	int ret = inet_aton(ip, &net_addr);
	if (ret == 0) {
		perror("Fail to inet_aton");
		exit(EXIT_FAILURE);
	}
	printf("net_addr = %#x\n", net_addr.s_addr);
}
