#include <stdio.h>

void exchange(int *q1, int *q2, int *q3);

int main(int argc, char **argv)
{ // tips: main 函数要能在命令行里接收参数
  int a, b, c;
  int *p1, *p2, *p3;
  printf("please enter 3 integer number:");
  scanf("%d%d%d", &a, &b, &c);

  p1 = &a;
  p2 = &b;
  p3 = &c;
  exchange(p1, p2, p3);
  printf("the order is :%d,%d,%d\n", a, b, c);

  return 0;
}

void exchange(int *q1, int *q2, int *q3)
{
  void swap(int *pt1, int *pt2);
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
