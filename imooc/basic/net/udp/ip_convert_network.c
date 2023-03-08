#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include "ip_convert_network.h"

void ip_convert(const char* ip) {
	in_addr_t net_addr = inet_addr(ip);
	if (net_addr == INADDR_NONE) {
		perror("Fail to inet_addr");
		exit(EXIT_FAILURE);
	}
	printf("net_addr = %#x\n", net_addr);

	struct in_addr addr;
	addr.s_addr = net_addr;
	printf("ip = %s\n", inet_ntoa(addr));

/*
 	struct in_addr addr = *((struct in_addr*)&net_addr);
	printf("ip = %s\n", inet_ntoa(addr));
 */
}
