cmake_minimum_required(VERSION 3.10)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c student_manager.h student_manager.c linklist.h linklist.c)
