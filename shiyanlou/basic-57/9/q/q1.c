#include <stdio.h>
// 编写函数 fun，其功能是：用户输入一个数 m，打印 1~m 能被 7 或 11 整除的所有整数。

int main()
{
  void fun(int num);
  int num;
  scanf("%d", &num);
  for (int i = 7; i < num; i++)
    fun(i);
  return 0;
}

void fun(int num)
{
  if (num % 7 == 0 || num % 11 == 0)
    printf("%d ", num);
}
