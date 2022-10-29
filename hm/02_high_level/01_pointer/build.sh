clear
cmake CMakeLists.txt
make
echo "-----------------------"
./01_pointer
echo "-----------------------"
make clean
rm -rf Makefile cmake_install.cmake CMakeCache.txt CMakeFiles
