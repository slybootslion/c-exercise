#include <stdio.h>
#include <math.h>

int main()
{
  double base, exponent;
  printf("基数：");
  scanf("%lf", &base);
  printf("指数：");
  scanf("%lf", &exponent);
  printf("%.1lf^%.1lf=%.2lf\n", base, exponent, pow(base, exponent));

  return 0;
}
