// 有 n 个人围成一圈，顺序排号。从第一个人开始报数（从 1 报到 3），凡是报到 3 的人退出圈子，问最后留下的是原来第几号的那位。

#include <stdio.h>
#define N 128

int main()
{
  int a[N] = {0};
  int out = 0, num = 0, *p = a;
  while (1)
  {
    if (*p == 0)
    {
      if (out == (N - 1))
        break;
      num++;
      num %= 3;
      if (num == 0)
      {
        *p = 1;
        out++;
      }
    }
    p++;
    if (p == a + N)
      p = a;
  }
  printf("最后剩余者的编号是：%ld", p + 1 - a);
  return 0;
}
