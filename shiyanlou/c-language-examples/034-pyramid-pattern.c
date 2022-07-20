#include <stdio.h>

// 使用 * 号
void m1(int rows)
{
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

// 使用数字
void m2(int rows)
{
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%d ", j);
    }
    printf("\n");
  }
}

// 使用字母
void m3(int rows)
{
  char alphabet = 'A';

  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%c ", alphabet);
    }
    alphabet++;
    printf("\n");
  }
}

// 倒三角形
void m4(int rows)
{
  for (int i = rows; i > 0; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }
}

// 倒三角数字
void m5(int rows)
{
  for (int i = rows; i >= 1; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%d ", j);
    }
    printf("\n");
  }
}

// 金字塔
void m6(int rows)
{
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= rows - i; j++)
    {
      printf(" ");
    }
    int k = 0;
    while (k != 2 * i - 1)
    {
      printf("*");
      k++;
    }
    printf("\n");
  }
}

// 数字金字塔
void m7(int rows)
{
  int count = 0, count1 = 0, k = 0;
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= rows - i; j++)
    {
      printf("  ");
      count++;
    }
    while (k != 2 * i - 1)
    {
      if (count <= rows - 1)
      {
        printf("%d ", i + k);
        count++;
      }
      else
      {
        count1++;
        printf("%d ", i + k - 2 * count1);
      }
      k++;
    }
    count1 = count = k = 0;
    printf("\n");
  }
}

// 倒金字塔
void m8(int rows)
{
  for (int i = rows; i >= 1; i--)
  {
    for (int j = 0; j < rows - i; j++)
      printf("  ");
    for (int j = i; j <= 2 * i - 1; j++)
      printf("* ");
    for (int j = 0; j < i - 1; j++)
      printf("* ");
    printf("\n");
  }
}

// 杨辉三角
void m9(int rows)
{
  int coef = 1;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 1; j < rows - i; j++)
    {
      printf("  ");
    }
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || i == 0)
        coef = 1;
      else
        coef = coef * (i - j + 1) / j;
      printf("%4d", coef); // %4d 数字前面补齐4位的空格。
    }
    printf("\n");
  }
}

// 佛洛依德三角形
void m10(int rows)
{
  for (int i = 1, j = 1; i <= rows; i++)
  {
    for (int l = 1; l <= i; l++)
    {
      printf("%5d", j);
      j++;
    }
    printf("\n");
  }
}

int main()
{
  int i, j, rows;
  printf("行数：");
  scanf("%d", &rows);

  m10(rows);
  return 0;
}
