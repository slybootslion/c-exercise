#include <stdio.h>

int main()
{
  int max4(int a, int b, int c, int d);
  int a, b, c, d, max;
  printf("please neter 4 integer number:\n");
  scanf("%d%d%d%d", &a, &b, &c, &d);
  max = max4(a, b, c, d);
  printf("%d\n", max);
  return 0;
}

int max2(int x, int y)
{
  return x > y ? x : y;
}

int max4(int a, int b, int c, int d)
{
  int m = max2(a, b);
  m = max2(m, c);
  m = max2(m, d);
  return m;
}
