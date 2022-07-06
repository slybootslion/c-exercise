// 输入 3 个整数 a，b，c 要求按从大到小的顺序将他们输出，用函数实现。

#include <stdio.h>

int main()
{
  void exchange(int *q1, int *q2, int *q3);
  int a, b, c;
  printf("please enter 3 integer number:");
  scanf("%d%d%d", &a, &b, &c);
  int *p1 = &a;
  int *p2 = &b;
  int *p3 = &c;
  exchange(p1, p2, p3);

  printf("the order is: %d, %d, %d\n", a, b, c);

  return 0;
}

void exchange(int *q1, int *q2, int *q3)
{
  void swap(int *p1, int *p2);
  if (*q1 < *q2)
    swap(q1, q2);
  if (*q1 < *q3)
    swap(q1, q3);
  if (*q2 < *q3)
    swap(q2, q3);
}

void swap(int *p1, int *p2)
{
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
