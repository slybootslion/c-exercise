#include <stdio.h>

int main()
{
  int a, b, c, t;
  printf("input three number:");
  scanf("%d%d%d", &a, &b, &c);

  a > b ? (t = a, a = b, b = t) : 0;
  a > c ? (t = a, a = c, c = t) : 0;
  b > c ? (t = b, b = c, c = t) : 0;

  printf("a=%d, c=%d, b=%d\n", a, b, c);

  return 0;
}
