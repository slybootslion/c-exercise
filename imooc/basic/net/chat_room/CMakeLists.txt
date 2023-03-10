cmake_minimum_required(VERSION 3.24)
project(chat_room C)

set(CMAKE_C_STANDARD 11)

add_executable(chat_room main.c server/linklist.c server/linklist.h server/udp_server.c client/udp_client.c client/udp_client.c)
