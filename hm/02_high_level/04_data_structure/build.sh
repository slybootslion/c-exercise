clear
cmake CMakeLists.txt
make
echo "-----------------------"
./04_data_structure
echo "-----------------------"
make clean
rm -rf Makefile cmake_install.cmake CMakeCache.txt CMakeFiles
