#include <stdio.h>

int main()
{
  double i;
  double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;

  printf("你的净利润是：\n");
  scanf("%lf", &i);

  bonus1 = 100000 * 0.1;
  bonus2 = bonus1 + 100000 * 0.075;
  bonus4 = bonus2 + 200000 * 0.05;
  bonus6 = bonus4 + 400000 * 0.015;
  bonus10 = bonus6 + 400000 * 0.015;

  if (i <= 100000)
  {
    bonus = i * 0.1;
  }
  else if (i <= 200000)
  {
    bonus = bonus1 + (i - 100000) * 0.075;
  }
  else if (i <= 400000)
  {
    bonus = bonus2 + (i - 200000) * 0.05;
  }
  else if (i <= 600000)
  {
    bonus = bonus4 + (i - 400000) * 0.03;
  }
  else if (i <= 1000000)
  {
    bonus = bonus6 + (i - 600000) * 0.015;
  }
  else if (i > 1000000)
  {
    bonus = bonus10 + (i - 1000000) * 0.01;
  }

  printf("提成为：bonus=%.2lf\n", bonus);

  return 0;
}
