#include <stdio.h>

int main()
{
  int firstNumber, secondNumber, sumOfTwoNumbers;
  printf("输入两个数（以空格分割）：");
  scanf("%d %d", &firstNumber, &secondNumber);
  sumOfTwoNumbers = firstNumber + secondNumber;
  printf("%d + %d = %d\n", firstNumber, secondNumber, sumOfTwoNumbers);
  return 0;
}
