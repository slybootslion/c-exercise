#include <stdio.h>

// 输入 20 个实数存放在一维数组中，输出它们的平均值以及高于平均的数的个数。

int main()
{
  int nums[20];
  int ave, sum;
  int count;

  int i;
  for (i = 0; i < 20; i++)
    scanf("%d", &nums[i]);

  for (i = 0; i < 20; i++)
    sum += nums[i];
  
  ave = sum / 20;

  for (i = 0; i < 20; i++)
    if (nums[i] > ave)
      count++;

  printf("ave=%d,num bigger than ave is %d\n", ave, count);
  return 0;
}
