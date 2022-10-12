cmake_minimum_required(VERSION 3.16)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c cmd_handle.c cmd_handle.h cmd_cp.c cmd_cp.h cmd_ls.c cmd_ls.h)
