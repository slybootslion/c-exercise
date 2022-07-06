#include <stdio.h>

int max (int a, int b){
  return a > b ? a : b;
}

int main () {
  int nums[10], m, n, i;
  printf("please neter 10 integer number:");
  for (i = 0; i < 10; i++)
    scanf("%d", &nums[i]);
  printf("\n");

  for (i = 1, m = nums[0], n = 0; i < 10; i++){
    if (max(m, nums[i]) > m){
      m = max(m, nums[i]);
      n = i + 1;
    }
  }

  printf("the largest number is %d\n it is the %dth number \n", m, n);

  return 0;
}
