#include <stdio.h>
#include "sum.h"

int main(int argc, char *argv[]) {
  int a, b;
  printf("input 2 nums:");
  scanf("%d%d", &a, &b);

  int res = sum(a, b);
  printf("sum = %d\n", res);
  return 0;
}
