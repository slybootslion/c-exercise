cmake_minimum_required(VERSION 3.24.3)
project(udp C)

set(CMAKE_C_STANDARD 11)

add_executable(udp main.c ip_convert.c ip_convert.h ip_convert_network.c ip_convert_network.h ip_port.c ip_port.h udp_send.c udp_send.h udp_recv.c udp_recv.h udp_fork_server.c)
