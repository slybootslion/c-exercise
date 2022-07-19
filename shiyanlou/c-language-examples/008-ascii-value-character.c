#include <stdio.h>
int main()
{
  char c;
  printf("输入一个字符：");
  scanf("%c", &c);
  printf("%c的ASCII为%d\n", c, c);
  return 0;
}
