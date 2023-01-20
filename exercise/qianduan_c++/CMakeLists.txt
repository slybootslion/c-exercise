cmake_minimum_required(VERSION 3.25)
project(qianduan_c__)

set(CMAKE_CXX_STANDARD 20)

add_executable(qianduan_c__ main.cpp 01_描述事物：自定义类型/Message.cpp 01_描述事物：自定义类型/Message.h 02_面向对象构建世间万物/Message.cpp 02_面向对象构建世间万物/Message.h 03_让开发者更省心的智能指针/Message.cpp 03_让开发者更省心的智能指针/Message.h 04_一句顶一万句：模板/getLargestNumber.cpp 04_一句顶一万句：模板/getLargestNumber.h 05_头等公民：函数/Function_ex.cpp 05_头等公民：函数/Function_ex.h 06_兵器库：常用的工具/tools.cpp 06_兵器库：常用的工具/tools.h 08_并行处理：线程/thread.cpp 07_包罗万象：容器/content.cpp 07_包罗万象：容器/content.h 08_并行处理：线程/thread.h 09_使用标准库处理文件/filesys.cpp 09_使用标准库处理文件/filesys.h)

find_package(Threads REQUIRED)
target_link_libraries(qianduan_c__ Threads::Threads)
