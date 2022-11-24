cmake_minimum_required(VERSION 3.16)
project(02_basic2)

set(CMAKE_CXX_STANDARD 14)

add_executable(02_basic2 main.cpp head.h 01_my_string/my_string.cpp 01_my_string/my_string.h 01_my_string/test_string.cpp)
