#include <stdio.h>
void divide()
{
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int even[10], odd[10];
  int e = 0, d = 0;
  for (int i = 0; i < 10; i++)
  {
    if (array[i] % 2 == 0)
    {
      even[e] = array[i];
      e++;
    }
    else
    {
      odd[e] = array[i];
      d++;
    }
  }

  printf("\n原始数组：");
  for (int i = 0; i < 10; i++)
    printf("%d ", array[i]);

  printf("\n偶数数组：");
  for (int i = 0; i < e; i++)
    printf("%d ", even[i]);

  printf("\n奇数数组：");
  for (int i = 0; i < d; i++)
    printf("%d ", odd[i]);
  printf("\n");
}

void concatenation()
{
  int array[10];
  int even[5] = {0, 2, 4, 6, 8};
  int odd[5] = {1, 3, 5, 7, 9};

  int e_len = 5, o_len = 5, index = 0;

  for (int i = 0; i < e_len; i++)
  {
    array[index] = even[i];
    index++;
  }

  for (int i = 0; i < o_len; i++)
  {
    array[index] = odd[i];
    index++;
  }

  printf("\n偶数：");
  for (int i = 0; i < e_len; i++)
    printf("%d ", even[i]);

  printf("\n奇数：");
  for (int i = 0; i < o_len; i++)
    printf("%d ", odd[i]);

  printf("\n合并后：");
  for (int i = 0; i < 10; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main()
{
  divide();
  concatenation();
  return 0;
}
