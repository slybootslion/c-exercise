clear
cmake CMakeLists.txt
make
echo "-----------------------"
./03_link
echo "-----------------------"
make clean
rm -rf Makefile cmake_install.cmake CMakeCache.txt CMakeFiles
