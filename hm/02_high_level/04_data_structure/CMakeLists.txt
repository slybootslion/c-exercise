cmake_minimum_required(VERSION 3.16)
project(04_data_structure C)

set(CMAKE_C_STANDARD 11)

add_executable(04_data_structure main.c 01_dynamic_array.c head.h lib_dynamic_array/lib_dynamic_array.c lib_dynamic_array/lib_dynamic_array.h 02_linklist.c lib_linklist_basic/lib_linklist.c lib_linklist_basic/lib_linklist.h lib_linklist_company/lib_linklist_c.c lib_linklist_company/lib_linklist_c.h 03_linklist_company.c 04_sequence_stack.c lib_sequence_stack/lib_sequence_stack.c lib_sequence_stack/lib_sequence_stack.h)
