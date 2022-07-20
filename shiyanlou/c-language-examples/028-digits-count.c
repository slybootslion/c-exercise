#include <stdio.h>

int main()
{
  long long n;
  printf("输入一个整数：");
  scanf("%lld", &n);

  int count = 0;
  while (n != 0)
  {
    n /= 10;
    count++;
  }

  printf("数字是%d位数。\n", count);
}
