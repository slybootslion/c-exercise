#include <stdio.h>

int m1(int n1, int n2)
{
  int minMultiple = n1 > n2 ? n1 : n2;

  while (1)
  {
    if (minMultiple % n1 == 0 && minMultiple % n2 == 0)
    {
      printf("%d和%d的最小公倍数%d\n", n1, n2, minMultiple);
      break;
    }
    minMultiple++;
  }
}

int m2(int n1, int n2)
{
  int gcd, lcm;
  for (int i = 1; i <= n1 && i <= n2; i++)
  {
    if (n1 % i == 0 && n2 % i == 0)
      // 最大公约数
      gcd = i;
  }
  lcm = (n1 * n2) / gcd;
  printf("%d和%d的最小公倍数为%d\n", n1, n2, lcm);
  return 0;
}

int main()
{
  int n1, n2, minMultiple;
  printf("输入两个正整数：");
  scanf("%d %d", &n1, &n2);

  // m1(n1, n2);
  m2(n1, n2);

  return 0;
}
