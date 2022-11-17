#include <iostream>
#include <cstring>
using namespace std;

void func(char *&temp) {
  char *p = (char *) malloc(64);
  memset(p, 0, 64);
  strcpy(p, "zhangsan");
  temp = p;
}

void test() {
  char *mp = NULL;
  func(mp);
  cout << mp << endl;
}

int main() {
  test();
  return 0;
}
