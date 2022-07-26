#include <stdio.h>
int main()
{
  char line[150];
  printf("输入一个字符\n");
  fgets(line, (sizeof line / sizeof line[0]), stdin);

  for (int i = 0; line[i] != '\0'; i++)
  {
    while (!(line[i] >= 'a' && line[i] <= 'z' || line[i] >= 'A' && line[i] <= 'Z' || line[i] == '\0'))
    {
      int j;
      for (j = i; line[j] != '\0'; j++)
      {
        line[j] = line[j + 1];
      }
      line[j] = '\0';
    }
  }
  
  printf("输出：");
  puts(line);
  return 0;
}
