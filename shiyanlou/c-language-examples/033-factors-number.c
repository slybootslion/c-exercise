#include <stdio.h>

int main()
{
  int number, i;

  printf("输入一个整数：");
  scanf("%d", &number);

  printf("%d的因数有：", number);
  for (int i = 1; i < number; i++)
  {
    if (number % i == 0)
      printf("%d ", i);
  }
  printf("\n");
  return 0;
}
