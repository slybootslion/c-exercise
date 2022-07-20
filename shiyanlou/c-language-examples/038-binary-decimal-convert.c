#include <stdio.h>
#include <math.h>

int convertBinaryToDecimal(long long n);
long long covertDecimalToBinary(long long n);

int main()
{
  long long n;
  int flag;
  printf("选择二进制转十进制（1），还是十进制转二进制（2）：");
  scanf("%d", &flag);

  if (flag == 1)
  {
    printf("输入一个二进制数：");
    scanf("%lld", &n);
    printf("二进制数%lld转换为十进制为%d\n", n, convertBinaryToDecimal(n));
  }
  else
  {
    printf("输入一个十进制数：");
    scanf("%lld", &n);
    printf("十进制数%lld转换为二进制为%lld\n", n, covertDecimalToBinary(n));
  }

  return 0;
}

int convertBinaryToDecimal(long long n)
{
  int decimalNumber = 0, i = 0, remainder;
  while (n != 0)
  {
    remainder = n % 10;
    n /= 10;
    decimalNumber += remainder * pow(2, i);
    i++;
  }
  return decimalNumber;
}

long long covertDecimalToBinary(long long n)
{
  long long binaryNumber = 0;
  int remainder, i = 1, step = 1;
  while (n != 0)
  {
    remainder = n % 2;
    printf("Step %d：%lld/2, 余数=%d， 商=%lld\n", step++, n, remainder, n / 2);
    n /= 2;
    binaryNumber += remainder * i;
    i *= 10;
  }
  return binaryNumber;
}
