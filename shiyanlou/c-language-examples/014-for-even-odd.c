#include <stdio.h>

int main()
{
  int i;
  printf("输入一个整数：");
  scanf("%d", &i);

  for (int n = 1; n <= i; n++)
  {
    if (i % 2)
    {
      if (n % 2)
        printf("%d\n", n);
    }
    else
    {
      if (!(n % 2))
        printf("%d\n", n);
    }
  }

  return 0;
}
