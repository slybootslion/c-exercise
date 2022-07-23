#include <stdio.h>
#include <math.h>

int main()
{
  float data[10];
  float calculateSD(float data[]);

  printf("输入10个元素：");
  for (int i = 0; i < 10; i++)
    scanf("%f", &data[i]);
  // 反映一组测量数据离散程度的统计指标。
  printf("\n标准偏差 = %.6f\n", calculateSD(data));

  return 0;
}

float calculateSD(float data[])
{
  float sum = 0.0, standardDeviation = 0.0;

  for (int i = 0; i < 10; i++)
  {
    sum += data[i];
  }

  float mean = sum / 10;

  for (int i = 0; i < 10; i++)
    standardDeviation += pow(data[i] - mean, 2);

  return sqrt(standardDeviation / 10);
}
