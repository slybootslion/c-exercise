#include <stdio.h>

int abs(int num)
{
  return num > 0 ? num : -num;
}

int hcf(int n1, int n2)
{
  if (n2 != 0)
    return hcf(n2, n1 % n2);
  else
    return n1;
}

int main()
{
  int n1, n2;
  printf("输入两个数：");
  scanf("%d%d", &n1, &n2);

  n1 = abs(n1);
  n2 = abs(n2);

  /* while (n1 != n2)
  {
    if (n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  printf("GCD=%d\n", n1); */
  printf("%d 和 %d 的最大公约数为 %d\n", n1, n2, hcf(n1,n2));

  return 0;
}
