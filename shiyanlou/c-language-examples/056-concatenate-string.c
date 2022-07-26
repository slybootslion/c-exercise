#include <stdio.h>

int main()
{
  char s1[100], s2[100], i, j;

  printf("输入第一个字符串：");
  scanf("%s", s1);

  printf("输入第二个字符串：");
  scanf("%s", s2);

  for (i = 0; s1[i] != '\0'; i++)
    ;
  for (j = 0; s2[i] != '\0'; j++)
  {
    s1[i] = s2[j];
  }
  s1[i] = '\0';

  printf("连接后：%s", s1);

  return 0;
}
