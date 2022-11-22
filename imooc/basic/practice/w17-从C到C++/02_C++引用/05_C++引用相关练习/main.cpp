#include <iostream>
using namespace std;

void my_swap_p(int *a, int *b) {
  int p = *a;
  *a = *b;
  *b = p;
}

void my_swap_r(int &a, int &b) {
  int r = a;
  a = b;
  b = r;
}

int main() {
  int a = 10, b = 20;
  cout << "a = " << a << " b = " << b << endl;
  my_swap_p(&a, &b);
  cout << "changed ---> a = " << a << " b = " << b << endl;
  my_swap_r(a, b);
  cout << "changed ---> a = " << a << " b = " << b << endl;
  return 0;
}
