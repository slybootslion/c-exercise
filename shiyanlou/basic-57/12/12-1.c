#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  char ch, filename[10];
  printf("please enter the file name:");
  scanf("%s", filename);

  fp = fopen(filename, "w");
  if (fp == NULL)
  {
    printf("Unable to open this file\n");
    exit(0);
  }

  printf("please enter a string in the disk (ends with a #):");
  ch = getchar();
  while (ch != '#')
  {
    fputc(ch, fp);
    putchar(ch);
    ch = getchar();
  }

  fclose(fp);
  putchar(10);
  return 0;
}
