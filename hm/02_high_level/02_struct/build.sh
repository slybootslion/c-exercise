clear
cmake CMakeLists.txt
make
echo "-----------------------"
./02_struct
echo "-----------------------"
make clean
rm -rf Makefile cmake_install.cmake CMakeCache.txt CMakeFiles
