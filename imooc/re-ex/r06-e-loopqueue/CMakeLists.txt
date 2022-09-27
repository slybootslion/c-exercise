cmake_minimum_required(VERSION 3.24)
project(r06_e_loopqueue C)

set(CMAKE_C_STANDARD 11)

add_executable(r06_e_loopqueue main.c loopqueue.c loopqueue.h)
