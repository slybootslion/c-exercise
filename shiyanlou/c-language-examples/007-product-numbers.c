#include <stdio.h>

int main()
{
  double firstNumber, secondNumber, product;
  printf("输入两个浮点数：");
  scanf("%lf %lf", &firstNumber, &secondNumber);
  product = firstNumber * secondNumber;
  printf("结果= %.2lf\n", product);
  return 0;
}
