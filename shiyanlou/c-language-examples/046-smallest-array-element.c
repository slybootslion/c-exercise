#include <stdio.h>

int main ()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int smallest = arr[0];
  for (int i = 0; i < 10; i++)
    smallest = arr[i] < smallest ? arr[i] : smallest;
  printf("最小元素为：%d\n", smallest);
  
  return 0;
}
