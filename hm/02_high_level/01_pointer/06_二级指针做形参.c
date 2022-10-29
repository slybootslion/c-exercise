#include "head.h"

void print_array(int **arr, int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", *arr[i]);
  printf("\n");
}

// 主调函数分配内存(堆上开辟)
void high_level_point_in() {
  int a1 = 10, a2 = 20, a3 = 30, a4 = 40, a5 = 50;
  int narr[] = {a1, a2, a3, a4, a5};
  int len = sizeof(narr) / sizeof(narr[0]);
  int **arr = (int **) malloc(sizeof(int *) * len);
  for (int i = 0; i < len; ++i)
    arr[i] = &narr[i];

  print_array(arr, len);
  if (arr != NULL) {
    free(arr);
    arr = NULL;
  }
}

// 再栈上开辟内存
void high_level_point_stack() {
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

void allocate_space_02(int **p) {
  int *p_array = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i)
    p_array[i] = i + 10;
  *p = p_array;
}

void print_array2(int **p, int n) {
  for (int i = 0; i < n; ++i)
    printf("%d ", (*p)[i]);
}

// 二级指针参数做输出特性
void high_level_point_out() {
  int *p = NULL;
  allocate_space_02(&p);
  print_array2(&p, 10);
  free_space((char **)&p);
  if (p == NULL)
    printf("\np为空指针\n");
}
