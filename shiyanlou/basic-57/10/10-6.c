#include <stdio.h>

int main()
{
  int a[10], i;
  printf("please enter 10 integer number:");
  for (i = 0; i < 10; i++)
    scanf("%d", &a[i]);
  for (i = 0; i < 10; i++)
    printf("%d ", *(a + i)); // 通过数组名和元素序号来计算元素的地址，再找该元素。
  return 0;
}
