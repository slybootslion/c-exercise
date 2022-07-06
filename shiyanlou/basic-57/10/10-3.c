// 输入两个整数，按先大后小的顺序输出 a 和 b。
// 用函数来进行

#include <stdio.h>

int main()
{
  void swap(int *point_1, int *point_2);
  int a, b;
  printf("please enter two integer number:");
  scanf("%d%d", &a, &b);
  int *p1 = &a;
  int *p2 = &b;
  if (a < b)
    swap(p1, p2);
  printf("max=%d, min=%d\n", a, b);
  return 0;
}

void swap(int *p1, int *p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
