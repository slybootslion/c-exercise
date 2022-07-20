#include <stdio.h>
#include <math.h>

int convertBinarytoOctal(long long binaryNumber);
long long convertOctalToBinary(int octalNumber);

int main()
{
  int n1, flag;
  long long n;

  printf("选择八进制转二进制（1），还是二进制转八进制（2）：");
  scanf("%d", &flag);

  if (flag == 1)
  {
    printf("输入一个八进制数：");
    scanf("%d", &n1);
    printf("八进制数%d转换为二进制为%lld\n", n1, convertOctalToBinary(n1));
  }
  else
  {
    printf("输入一个二进制数：");
    scanf("%lld", &n);
    printf("二进制数%lld转换为八进制为%d\n", n, convertBinarytoOctal(n));
  }

  return 0;
}

int convertBinarytoOctal(long long binaryNumber)
{
  int octalNumber = 0, decimalNumber = 0, i = 0;
  while (binaryNumber != 0)
  {
    decimalNumber += binaryNumber % 10 * pow(2, i);
    i++;
    binaryNumber /= 10;
  }
  i = 1;
  while (decimalNumber != 0)
  {
    octalNumber += decimalNumber % 8 * i;
    decimalNumber /= 8;
    i *= 10;
  }

  return octalNumber;
}

long long convertOctalToBinary(int octalNumber)
{
  int decimalNumber = 0, i = 0;
  long long binaryNumber = 0;

  while (octalNumber != 0)
  {
    decimalNumber += (octalNumber % 10) * pow(8, i);
    i++;
    octalNumber /= 10;
  }
  i = 1;
  while (decimalNumber != 0)
  {
    binaryNumber += decimalNumber % 2 * i;
    decimalNumber /= 2;
    i *= 10;
  }

  return binaryNumber;
}
