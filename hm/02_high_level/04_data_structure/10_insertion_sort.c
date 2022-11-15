#include "head.h"

void insert_sort(int arr[], int len) {
  for (int i = 1; i < len; ++i) {
    if (arr[i] < arr[i - 1]) {
      int temp = arr[i];
      int j = i - 1;
      for (; j > 0 && temp < arr[j]; --j)
        arr[j + 1] = arr[j];
      arr[j + 1] = temp;
    }
  }
}

void insert_sort_exercise() {
  int arr[] = {1, 5, 3, 4, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  putchar('\n');
  print_line();

  insert_sort(arr, len);

  for (int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  putchar('\n');
  print_line();
}
