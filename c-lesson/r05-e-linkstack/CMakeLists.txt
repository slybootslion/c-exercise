cmake_minimum_required(VERSION 3.24)
project(r05_e_linkstack C)

set(CMAKE_C_STANDARD 11)

add_executable(r05_e_linkstack main.c linkstack.c linkstack.h)
