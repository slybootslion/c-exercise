#include <stdio.h>

int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int lagest = arr[0];
  for (int i = 0; i < 10; i++)
    lagest = (arr[i] > lagest) ? arr[i] : lagest;
  printf("最大元素为：%d\n", lagest);

  return 0;
}
