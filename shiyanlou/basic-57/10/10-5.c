// 有一个整型数组 a，有 10 个元素，要求输出数组中的全部元素。

#include <stdio.h>

int main()
{

  int a[10], i;
  printf("please enter 10 integer number:");
  for (i = 0; i < 10; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < 10; i++)
    printf("%d ", a[i]);

  return 0;
}
