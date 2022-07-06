// 编写函数 fun，其功能是将两个两位数的正整数 a、b 合并成一个整数放在 c 中。合并的方式是：将 a 数的十位和个位依次放在 c 数的十位和千位上，b 数的十位和个位依次放在 c 数的百位和个位上。

// 例如，当 a=45，b=12 时，调用该函数后，c=5142。
#include <stdio.h>

void fun(int a, int b)
{
  int c = a % 10 * 1000 + a / 10 * 10 + b / 10 * 100 + b % 10;
  printf("%d", c);
}

int main()
{
  int a, b;
  scanf("%d%d", &a, &b);
  if (a < 10 || a > 99 || b < 10 || b > 99)
    printf("error!");
  else
    fun(a, b);
  return 0;
}
