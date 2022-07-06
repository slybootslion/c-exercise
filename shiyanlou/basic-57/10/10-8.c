#include <stdio.h>

int main()
{
  int i, *p, a[10];
  p = a;
  printf("please enter 10 integer number:");
  for (i = 0; i < 10; i++)
    scanf("%d", p++);
  // 第一次循环结束后，指针已经指向数组末尾，这里将指针再指回数组开始
  p = a;
  for (i = 0; i < 10; i++, p++)
    printf("%d ", *p);
  printf("\n");
  return 0;
}
