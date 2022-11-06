cmake_minimum_required(VERSION 3.16)
project(03_link C)

set(CMAKE_C_STANDARD 11)

add_executable(03_link main.c head.h 01_静态链表和动态链表.c 02_带头节点链表.c)
