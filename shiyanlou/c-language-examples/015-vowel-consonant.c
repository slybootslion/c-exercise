#include <stdio.h>

int main()
{
  char c;
  int isLowercaseVowel, isUppercaseVowel;

  printf("输入一个字母：");
  scanf("%c", &c);

  isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

  if (isLowercaseVowel || isUppercaseVowel)
    printf("%c是元音\n", c);
  else
    printf("%c是辅音\n", c);

  return 0;
}
