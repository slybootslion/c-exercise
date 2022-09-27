cmake_minimum_required(VERSION 3.24)
project(r03_e_looplink C)

set(CMAKE_C_STANDARD 11)

add_executable(r03_e_looplink main.c looplink.c looplink.h)
