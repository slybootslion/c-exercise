cmake_minimum_required(VERSION 3.16)
project(03_operation_file C)

set(CMAKE_C_STANDARD 11)

add_executable(03_operation_file main.c head.h 01_operation_file.c encryption.c)
