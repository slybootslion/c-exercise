cmake_minimum_required(VERSION 3.16)
project(01_basic)

set(CMAKE_CXX_STANDARD 17)

add_executable(01_basic main.cpp 01_class_basic.cpp head.h 02_c++调用c/c_file.c 02_c++调用c/c_file.h 02_c++调用c/c++_file.cpp 03_constructor_function.cpp 04_deep_clone.cpp 05_static_prop.cpp 06_single_mod.cpp 07_this.cpp 08_exercise01.cpp "09_my_array/test_my_array.cpp" 09_my_array/my_array.cpp 09_my_array/my_array.h)
