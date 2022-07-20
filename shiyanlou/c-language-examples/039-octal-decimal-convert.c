#include <stdio.h>
#include <math.h>

int convertDecimalToOctal(int decimalNumber);
int convertOctalToDecimal(int octalNumber);

int main()
{
  int flag, n;
  printf("选择八进制转十进制（1），还是十进制转八进制（2）：");
  scanf("%d", &flag);

  if (flag == 1)
  {
    printf("输入一个八进制数：");
    scanf("%d", &n);
    printf("八进制数%d转换为十进制为%d\n", n, convertOctalToDecimal(n));
  }
  else
  {
    printf("输入一个十进制数：");
    scanf("%d", &n);
    printf("十进制数%d转换为八进制为%d\n", n, convertDecimalToOctal(n));
  }

  return 0;
}

int convertDecimalToOctal(int decimalNumber)
{
  int octalNumber = 0, i = 1;
  while (decimalNumber != 0)
  {
    octalNumber += (decimalNumber % 8) * i;
    decimalNumber /= 8;
    i *= 10;
  }
  return octalNumber;
}

int convertOctalToDecimal(int octalNumber)
{
  int decimalNumber = 0, i = 0;
  while (octalNumber != 0)
  {
    decimalNumber += (octalNumber % 10) * pow(8, i);
    i++;
    octalNumber /= 10;
  }
  i = 1;
  return decimalNumber;
}
