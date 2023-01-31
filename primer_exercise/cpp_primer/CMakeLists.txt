cmake_minimum_required(VERSION 3.25)
project(cpp_primer)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_primer main.cpp chapter01/chapter01.cpp chapter01/chapter01.h utils/head.h chapter01/Sales_item.h chapter02/chapter02.cpp chapter02/chapter02.h chapter03/chapter03.cpp chapter03/chapter03.h utils/head.cpp)
