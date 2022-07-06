// 有一个一维数组 score，内放 10 个数，求平均值。
#include <stdio.h>

int main()
{
  float average(float scores[10]);
  float scores[10], ave;
  printf("please enter 10 scores:");
  for (int i = 0; i < 10; i++)
    scanf("%f", &scores[i]);
  printf("\n");
  ave = average(scores);
  printf("average score is %5.2f\n", ave);
  
  return 0;
}

float average(float scores[10])
{
  float ave, sum = 0;
  for (int i = 0; i < 10; i++)
  {
    sum += scores[i];
  }
  ave = sum / 10;
  return ave;
}
