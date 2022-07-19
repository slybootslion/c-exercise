#include <stdio.h>

int main()
{
  int n, i, sum = 0;
  printf("输入一个数：");
  scanf("%d", &n);

  for (i = 1; i <= n; i++)
    sum += i;
  printf("sum=%d\n", sum);

  return 0;
}
