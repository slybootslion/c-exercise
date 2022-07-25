#include <stdio.h>

// 矩阵转换
int main()
{
  int a[10][10], r, c;
  printf("输入矩阵的行与列：\n");
  scanf("%d %d", &r, &c);

  printf("输入矩阵元素：\n");
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
      printf("输入元素 a%d%d：", i + 1, j + 1);
      scanf("%d", &a[i][j]);
    }

  printf("\n输入矩阵：\n");
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
      printf("%d ", a[i][j]);
      if (j == c - 1)
        printf("\n\n");
    }

  int transponse[10][10];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
      transponse[j][i] = a[i][j];
    }
  
  printf("\n转换后矩阵：\n");
  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++)
    {
      printf("%d ", transponse[i][j]);
      if (j == r - 1)
        printf("\n\n");
    }
  
  return 0;
}
