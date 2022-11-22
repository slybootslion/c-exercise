#include <iostream>
using namespace std;

int calc(int a, int b, int c = 10) {
  return (a + b + c);
}

int main() {
  cout << calc(100, 200) << endl;
  return 0;
}


