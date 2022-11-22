#include <iostream>
using namespace std;
void init_data(int *&arr) {
  arr = new int[10];
}
void write_data(int *&arr) {
  for (int i = 0; i < 10; i++)
	arr[i] = i * 0x11;
}
void print_data(int *&arr) {
  for (int i = 0; i < 10; ++i)
	cout << (void*)arr[i] << endl;
  delete[] arr;
}
int main() {
  int *arr;
  init_data(arr);
  write_data(arr);
  print_data(arr);
  return 0;
}
