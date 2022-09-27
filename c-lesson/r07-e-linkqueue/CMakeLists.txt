cmake_minimum_required(VERSION 3.24)
project(r07_e_linkqueue C)

set(CMAKE_C_STANDARD 11)

add_executable(r07_e_linkqueue main.c linkstack.c linkstack.h)
