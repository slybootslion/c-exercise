/*
北京市出租车打车计费规则如下：
1. 每公里单价计费2.3元
2. 起步价13元(包含3公里)
3. 晚上23点(含)至次日凌晨5点(不含)打车，每公里单价计费加收20%。
4. 每次乘车加收1元钱的燃油附加税。
小明每天上下班都要打车，公司和家的距离为12公里，上午上班时间为9点，下午下班时间为6点。
请编写一个小程序计算小明每天打车的总费用。
 */

#include <stdio.h>

float distance = 12;
float unit_price = 2.3;
float tax = 1;

float pay(time)
{
  int money;
  if (time >= 23 || time < 5)
  {
    unit_price *= unit_price * 1.2;
  }
  return unit_price * distance + tax;
}

int main()
{
  int time;
  printf("输入上车时间：0-24\n");
  scanf("%d", &time);
  float pay_money = pay(time);
  printf("价格：%f", pay_money);
  return 0;
}
