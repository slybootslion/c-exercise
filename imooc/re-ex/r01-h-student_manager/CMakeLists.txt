cmake_minimum_required(VERSION 3.24)
project(r01_h_student_manager C)

set(CMAKE_C_STANDARD 11)

add_executable(r01_h_student_manager main.c student_manager.c student_manager.h linklist.c linklist.h)
