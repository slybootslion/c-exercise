#include <stdio.h>

void first()
{
  double firstNumber, secondNumber, temporaryVarialbe;

  printf("输入第两个数字：\n");
  scanf("%lf%lf", &firstNumber, &secondNumber);
  printf("\n交换前，第一个数字=%.2lf，第二个数字=%.2lf\n", firstNumber, secondNumber);

  temporaryVarialbe = firstNumber;
  firstNumber = secondNumber;
  secondNumber = temporaryVarialbe;

  printf("\n交换后，第一个数字=%.2lf，第二个数字=%.2lf\n", firstNumber, secondNumber);
}

void second()
{
  double firstNumber, secondNumber;

  printf("输入第两个数字：\n");
  scanf("%lf%lf", &firstNumber, &secondNumber);
  printf("\n交换前，第一个数字=%.2lf，第二个数字=%.2lf\n", firstNumber, secondNumber);

  firstNumber += secondNumber;
  secondNumber = firstNumber - secondNumber;
  firstNumber = firstNumber - secondNumber;

  printf("\n交换后，第一个数字=%.2lf，第二个数字=%.2lf\n", firstNumber, secondNumber);
}

int main()
{
  // 使用临时变量
  // first();
  // 不使用临时变量
  second();
  return 0;
}
