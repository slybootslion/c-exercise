#include <stdio.h>

int main()
{
  int checkPrime(int n);
  int n, flag;

  printf("输入正整数：");
  scanf("%d", &n);

  for (int i = 2; i <= n / 2; i++)
  {
    if (checkPrime(i) && checkPrime(n - i))
    {
      printf("%d = %d + %d\n", n, i, n - i);
      flag = 1;
    }
  }
  printf("%d", !flag);
  if (!flag)
    printf("%d不能分解位两个素数", n);

  return 0;
}

int checkPrime(int n)
{
  for (int i = 2; i <= n / 2; i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}
