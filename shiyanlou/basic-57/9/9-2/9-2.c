#include <stdio.h>

int main()
{
  int max(int x, int y);
  int a = 10, b = 11;
  int z = max(a, b);
  printf("%d\n", z);
  return 0;
}

int max(int x, int y)
{
  return x > y ? x : y;
}
