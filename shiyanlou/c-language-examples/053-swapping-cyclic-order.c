#include <stdio.h>

void cyclicSwap(int *a, int *b, int *c);

int main()
{
  int a, b, c;

  printf("输入a b c的值：\n");
  scanf("%d %d %d", &a, &b, &c);

  printf("交换前：\n");
  printf("a=%d \nb=%d \nc=%d\n", a, b, c);

  cyclicSwap(&a, &b, &c);

  printf("交换后：\n");
  printf("a=%d \nb=%d \nc=%d\n", a, b, c);

  return 0;
}

void cyclicSwap(int *a, int *b, int *c)
{
  int temp;
  temp = *b;
  *b = *a;
  *a = *c;
  *c = temp;
}
