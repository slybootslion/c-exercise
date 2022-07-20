#include <stdio.h>

int main()
{
  int n, reversedInteger = 0;
  printf("输入一个整数：");
  scanf("%d", &n);

  int origin = n, remainder;
  while (n != 0)
  {
    remainder = n % 10;
    reversedInteger = reversedInteger * 10 + remainder;
    n /= 10;
  }

  // 判断
  if (origin == reversedInteger)
    printf("%d是回文数\n", origin);
  else
    printf("%d不回文数\n", origin);
}
