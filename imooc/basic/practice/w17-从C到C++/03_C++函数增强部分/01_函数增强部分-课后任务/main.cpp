#include <iostream>
using namespace std;

void my_swap(float &a, float &b) {
  float temp = a;
  a = b;
  b = temp;
}

void my_swap(string &a, string &b) {
  string temp = a;
  a = b;
  b = temp;
}

int main() {
  float a = 0.1, b = 0.2;
  my_swap(a, b);
  cout << "a = " << a << " b = " << b << endl;

  string str1 = "World", str2 = "Hello";
  my_swap(str1, str2);
  cout << "str1 = " << str1 << " str2 = " << str2 << endl;
  return 0;
}
