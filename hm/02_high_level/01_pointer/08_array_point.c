#include "head.h"

// 数组指针定义的方式
void set_array_point() {
  int arr[10];
  int (*p)[10] = &arr;
  for (int i = 0; i < 10; ++i) {
    (*p)[i] = i + 1;
  }
  for (int i = 0; i < 10; ++i) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}
