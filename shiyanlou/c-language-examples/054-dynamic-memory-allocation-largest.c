#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num;
  printf("输入元素个数（1~100）：\n");
  scanf("%d", &num);

  float *data = (float *)calloc(num, sizeof(float));

  if (data == NULL)
  {
    printf("Error!内存没有分配");
    exit(0);
  }

  printf("\n");

  for (int i = 0; i < num; i++)
  {
    printf("输入数字 %d：", i + 1);
    scanf("%f", data + i);
  }

  for (int i = 1; i < num; i++)
  {
    if (*data < *(data + 1))
      *data = *(data + 1);
  }

  printf("最大元素=%.2f\n", *data);

  return 0;
}
