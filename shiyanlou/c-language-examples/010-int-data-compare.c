#include <stdio.h>

// int main ()
// {
//   int a, b;
//   printf("输入两个数\n");
//   scanf("%d%d", &a, &b);

//   if (a > b)
//     printf("a 大于 b\n");
//   else
//     printf("a 小于等于 b\n");

//   return 0;
// }

int main()
{
  int a, b, c;
  printf("输入三个数\n");
  scanf("%d%d%d", &a, &b, &c);

  int max = a;
  if (b > a && b > c)
    max = b;
  else if (c > a && c > b)
    max = c;
  else
  {
    printf("有两个或三个数值相等\n");
    return 0;
  }

  printf("%d 最大\n", max);
  return 0;
}
