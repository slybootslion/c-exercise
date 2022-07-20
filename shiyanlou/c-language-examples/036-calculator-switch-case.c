#include <stdio.h>

int main()
{
  char operator;
  double f, s;

  printf("输入操作符（+ - * /）：");
  scanf("%c", &operator);

  printf("输入两个数字：");
  scanf("%lf%lf", &f, &s);

  switch (operator)
  {
  case '+':
    printf("%.1lf + %.1lf = %.1lf\n", f, s, f + s);
    break;
  case '-':
    printf("%.1lf - %.1lf = %.1lf\n", f, s, f - s);
    break;
  case '*':
    printf("%.1lf * %.1lf = %.1lf\n", f, s, f * s);
    break;
  case '/':
    printf("%.1lf / %.1lf = %.1lf\n", f, s, f / s);
    break;
  default:
    printf("Error! operator is not correct\n");
  }

  return 0;
}
