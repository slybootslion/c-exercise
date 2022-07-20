#include <stdio.h>
#include <math.h>

int checkArmstrongNumber(int num)
{
  int originalNumber, remainder, result = 0, n = 0, flag;
  originalNumber = num;
  while (originalNumber != 0)
  {
    originalNumber /= 10;
    n++;
  }
  originalNumber = num;
  while (originalNumber != 0)
  {
    remainder = originalNumber % 10;
    result += pow(remainder, n);
    originalNumber /= 10;
  }

  if (result == num)
    return 1;
  else
    return 0;
}

int main()
{
  int n;
  printf("输入一个正整数");
  scanf("%d", &n);

  int flag = checkArmstrongNumber(n);
  if (flag)
    printf("%d是Armstrong数\n", n);
  else
    printf("%d不是Armstrong数\n", n);

  return 0;
}
