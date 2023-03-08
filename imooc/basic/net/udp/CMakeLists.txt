cmake_minimum_required(VERSION 3.25)
project(udp C)

set(CMAKE_C_STANDARD 11)

add_executable(udp main.c ip_convert.c ip_convert.h ip_convert_network.c ip_convert_network.h ip_port.c ip_port.h udp_send.c udp_send.h)
