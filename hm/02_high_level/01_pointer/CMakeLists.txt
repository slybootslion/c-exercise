cmake_minimum_required(VERSION 3.16)
project(01_pointer C)

set(CMAKE_C_STANDARD 11)

add_executable(01_pointer main.c 01_copy_string.c head.h 02_revers_string.c 03_pointer_arguments.c 04_high_level_point.c change_pointer.c 05_find_sub_string.c)

