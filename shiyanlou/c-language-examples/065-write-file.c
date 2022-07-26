#include <stdio.h>
#include <stdlib.h> /* exit()函数 */

int main()
{
  char sentence[1000];
  FILE *fptr;

  fptr = fopen("runoob.txt", "w");
  if (fptr == NULL)
  {
    printf("Error!打开文件报错");
    exit(1);
  }

  printf("输入字符串：\n");
  fgets(sentence, (sizeof sentence / sizeof sentence[0]), stdin);

  fprintf(fptr, "%s", sentence);
  fclose(fptr);

  return 0;
}
