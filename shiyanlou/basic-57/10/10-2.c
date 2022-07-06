// 输入两个整数，按先大后小的顺序输出 a 和 b。
// 用指针的方法来处理这个问题。不交换整形变量的值，而是交换两个指针变量的值。

#include <stdio.h>

int main()
{
  int *p1, *p2, a, b;
  printf("please enter two integer number:");
  scanf("%d%d", &a, &b);
  p1 = &a;
  p2 = &b;

  if (a < b)
  {
    p1 = &b;
    p2 = &a;
  }

  printf("a=%d, b=%d\n", a, b);
  printf("max=%d, min=%d\n", *p1, *p2);

  return 0;
}
