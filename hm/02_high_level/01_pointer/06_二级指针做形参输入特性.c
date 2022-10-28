#include "head.h"

void print_array(int **arr, int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", *arr[i]);
  printf("\n");
}

// 主调函数分配内存
void high_level_point_in() {
  int a1 = 10, a2 = 20, a3 = 30, a4 = 40, a5 = 50;
  int narr[] = {a1, a2, a3, a4, a5};
  int **arr = (int **) malloc(sizeof(int *) * 5);
  for (int i = 0; i < 5; ++i)
    arr[i] = &narr[i];

  print_array(arr, 5);

  free(arr);
  arr = NULL;
}

// 再栈上开辟内存
void high_level_point_in_stack() {
  int *p_arr[5];
  for (int i = 0; i < 5; ++i) {
    p_arr[i] = malloc(4);
    *p_arr[i] = i + 1;
  }
  int len = sizeof(p_arr) / sizeof(int *);
  print_array(p_arr, len);
  for (int i = 0; i < 5; ++i) {
    if (p_arr[i] != NULL) {
      free(p_arr[i]);
      p_arr[i] = NULL;
    }
  }
}
