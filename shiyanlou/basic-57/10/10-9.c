// 将数组 a 中 n 个整数按相反的顺序存放
#include <stdio.h>

int main()
{
  void change(int x[], int n);
  int i, a[10] = {3, 7, 9, 11, 0, 6, 7, 5, 4, 2};

  printf("the original arrar:\n");
  for (i = 0; i < 10; i++)
    printf("%d ", a[i]);
  printf("\n");

  change(a, 10);
  printf("the array has been inverted:\n");
  for (i = 0; i < 10; i++)
    printf("%d ", a[i]);
  return 0;
}

void change(int x[], int n)
{
  int temp, i, j, m = (n - 1) / 2;
  for (i = 0; i <= m; i++)
  {
    j = n - 1 - i;
    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
  }
}
