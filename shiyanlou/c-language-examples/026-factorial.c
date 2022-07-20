#include <stdio.h>

void m1(int n)
{
  unsigned long long factorial = 1;
  for (int i = 1; i <= n; i++)
  {
    factorial *= i;
  }
  printf("%d的阶乘为：%lld\n", n, factorial);
}

// 递归
long int multiplyNumbers(int n)
{
  if (n > 1)
    return n * multiplyNumbers(n - 1);
  else
    return 1;
}

int main()
{
  int n;
  printf("输入一个正整数：");
  scanf("%d", &n);
  if (n < 0)
  {
    printf("Error!负数没有阶乘！");
    return 0;
  }

  // m1(n);
  long int res = multiplyNumbers(n);
  printf("%d的阶乘为：%ld\n", n, res);

  return 0;
}
