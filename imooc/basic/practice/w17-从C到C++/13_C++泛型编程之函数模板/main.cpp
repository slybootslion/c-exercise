#include <iostream>

using namespace std;

template<typename T>
void my_swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

int main() {
  int a = 10;
  int b = 20;
  my_swap<int>(a, b);
  cout << "a: " << a << ", b: " << b << endl;

  string str1 = "aa";
  string str2 = "bb";
  my_swap<string>(str1, str2);
  cout << "str1: " << str1 << ", str2: " << str2 << endl;

  return 0;
}
