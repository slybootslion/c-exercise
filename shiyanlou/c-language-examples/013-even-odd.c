#include <stdio.h>

int main()
{
  int number;
  printf("请输入第一个整数：\n");
  scanf("%d", &number);

  if (number % 2 == 0)
    printf("%d是偶数\n", number);
  else
    printf("%d是奇数\n", number);

  return 0;
}
