#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include "ip_port.h"

void ip_convert_port(const char* ip, const char* port) {
	// host ip --> network bytes ip
	in_addr_t net_addr = inet_addr(ip);
	if (net_addr == INADDR_NONE) {
		perror("Fail to inet_addr");
		exit(EXIT_FAILURE);
	}
	printf("net_addr = %#x\n", net_addr);

	// host port --> network port
	uint16_t net_port = htons(atoi(port));
	printf("net_port = %#x\n", net_port);

	// network ip --> host ip
	struct in_addr addr;
	addr.s_addr = net_addr;
	printf("host_ip = %s\n", inet_ntoa(addr));

	// network port --> host port
	uint16_t host_port = ntohs(net_port);
	printf("host_port = %d\n", host_port);
}

void ip_port_convert(const char* ip, const char* port){
	// host ip --> network bytes ip
	struct in_addr net_addr;
	int res = inet_aton(ip, &net_addr);
	if (res == 0) {
		perror("Fail to inet_addr");
		exit(EXIT_FAILURE);
	}
	printf("net_addr = %#x\n", net_addr.s_addr);

	// host port --> network port
	uint16_t net_port = htons(atoi(port));
	printf("net_port = %#x\n", net_port);

	// network ip --> host ip
	struct in_addr addr;
	addr.s_addr = net_addr.s_addr;
	printf("host_ip = %s\n", inet_ntoa(addr));

	// network port --> host port
	uint16_t host_port = ntohs(net_port);
	printf("host_port = %d\n", host_port);
}
