clear
cmake CMakeLists.txt
make
clear
echo ------------------------------------
./01_basic
echo ------------------------------------
make clean
rm -rf Makefile cmake_install.cmake CMakeCache.txt CMakeFiles
