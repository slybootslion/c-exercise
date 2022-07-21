#include <stdio.h>

int main()
{
  int n;
  float num[100], sum = 0.0, average;

  printf("输入元素个数：");
  scanf("%d", &n);

  while (n > 100 || n <= 0)
  {
    printf("Error！数字需要在1到100中间。\n");
    printf("再次输入：");
    scanf("%d", &n);
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d，输入数字：", i + 1);
    scanf("%f", &num[i]);
    sum += num[i];
  }

  average = sum / n;
  printf("平均值=%.2f\n", average);

  return 0;
}
