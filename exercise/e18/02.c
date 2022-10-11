#include "head.h"

/*
 * 下面程序的功能是将一个4×4的数组进行逆时针旋转90度后输出，
 * 要求原始数组的数据随机输入，
 * 新数组以4行4列的方式输出
 * */

int main() {
  int a[4][4], b[4][4];

  printf("input 16 numbers:");
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      scanf("%d", &a[i][j]);
      b[3 - j][i] = a[i][j];
    }
  }

  printf("array b:\n");
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j)
      printf("%6d", b[i][j]);
    putchar('\n');
  }

  return 0;
}
