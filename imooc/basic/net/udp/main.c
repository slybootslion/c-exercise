#include <stdio.h>
#include <stdlib.h>
//#include "ip_convert.h"
//#include "ip_convert_network.h"
//#include "ip_port.h"
#include "udp_send.h"
#include "udp_recv.h"

int main(int argc, const char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
		exit(EXIT_FAILURE);
	}

//	ip_convert_first(argv[1]);
//	ip_convert_second(argv[1]);

//	ip_convert(argv[1]);

//	ip_convert_port(argv[1], argv[2]);
//	ip_port_convert(argv[1], argv[2]);

//	udp_send_ex(argv[1], argv[2]);

	udp_recv_ex(argv[1], argv[2]);
	return 0;
}
