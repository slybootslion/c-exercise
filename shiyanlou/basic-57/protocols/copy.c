#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc < 3)
    return 1;

  // 获取文件名
  char *file1 = argv[1];
  char *file2 = argv[2];

  FILE *fp1, *fp2;

  char ch;

  // 读取源文件
  if ((fp1 = fopen(file1, "r")) == NULL)
    printf("File isn't exist!\n");
  // 创建目的文件
  if ((fp2 = fopen(file2, "w")) == NULL)
    printf("File can't be created!\n");

  // 读取并写入文件
  while ((ch = fgetc(fp1)) != EOF)
    fputc(ch, fp2);

  fclose(fp1);
  fclose(fp2);
  return 0;
}
