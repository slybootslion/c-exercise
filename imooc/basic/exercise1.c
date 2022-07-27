#include <stdio.h>

int main()
{
  int a, b, c;
  a = a > b ? b = b > c ? c : b : a;
  printf("a=%d, b=%d, c=%d", a, b, c);
  return 0;
}
