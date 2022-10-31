#include "head.h"

void select_sort_int(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    int min = i;
    for (int j = i + 1; j < len; ++j) {
      if (arr[min] > arr[j])
        min = j;
    }
    if (i != min) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
}

void print_array4(int arr[], int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  putchar('\n');
}

void select_sort_string(char *arr[], int len) {
  for (int i = 0; i < len; ++i) {
    int max = i;
    for (int j = i + 1; j < len; ++j) {
      if (strcmp(arr[max], arr[j]) > 0) {
        max = j;
      }
    }
    if (i != max) {
      char *temp = arr[i];
      arr[i] = arr[max];
      arr[max] = temp;
    }
  }
}

void print_array5(char *p[], int len) {
  for (int i = 0; i < len; ++i)
    printf("%s ", p[i]);
  putchar('\n');
}

void select_sort_in() {
  int arr[] = {3, 5, 1, 2, 4};
  int len = sizeof(arr) / sizeof(arr[0]);
  select_sort_int(arr, len);
  print_array4(arr, len);

  char *p[] = {"b", "a", "c", "e", "d"};
  len = sizeof(p) / sizeof(p[0]);
  select_sort_string(p, len);
  print_array5(p, len);
}
