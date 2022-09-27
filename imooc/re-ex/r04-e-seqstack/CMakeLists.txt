cmake_minimum_required(VERSION 3.24)
project(r04_e_seqstack C)

set(CMAKE_C_STANDARD 11)

add_executable(r04_e_seqstack main.c seqstack.h seqstack.c)
