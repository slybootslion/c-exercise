cmake_minimum_required(VERSION 3.16)
project(0_C___STL___)

set(CMAKE_CXX_STANDARD 17)

add_executable(0_C___STL___ main.cpp 01_string/01_字符串构造函数.cpp 01_string/02_字符串对象赋值.cpp 01_string/03_字符串遍历操作.cpp 01_string/04_字符串添加与删除.cpp 01_string/05_字符串查找与替换.cpp 01_string/06_字符串与字符互转.cpp 01_string/07_字符串大小写互转.cpp 02_vector/vector.h 02_vector/01_数组向量的基本使用.cpp "02_vector/02_数组向量的正(反)向遍历.cpp" "02_vector/03_数组向量的正(反)向排序.cpp" 02_vector/04_向数组向量中插入元素.cpp 02_vector/05_向数组向量中插入结构指针.cpp 02_vector/06_向数组向量中插入类指针.cpp 02_vector/07_在数组容器中嵌套容器.cpp 02_vector/08_函数参数定义为容器类型.cpp 02_vector/09_数组向量元素的删除.cpp 03_map_multimap/01_通过对组实现键值对.cpp 03_map_multimap/map_multimap.h 03_map_multimap/02_正反向遍历映射容器.cpp)
