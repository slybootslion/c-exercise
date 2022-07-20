#include <stdio.h>

int main()
{
  char c;
  printf("输入u显示大写字母，输入l显示小写字母：");
  scanf("%c", &c);

  if (c == 'U' || c == 'u')
  {
    for (c = 'A'; c <= 'Z'; c++)
      printf("%c ", c);
    printf("\n");
  }
  else if (c == 'l' || c == 'L')
  {
    for (c = 'a'; c <= 'z'; c++)
      printf("%c ", c);
    printf("\n");
  }
  else
    printf("Error!输入非法字符。");

  return 0;
}
