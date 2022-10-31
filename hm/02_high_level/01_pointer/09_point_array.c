#include "head.h"

void array_sort(char **p, long len) {
  for (int i = 0; i < len; ++i) {
    for (long j = len - 1; j > i; --j) {
      if (strcmp(p[j - 1], p[j]) > 0) {
        char *temp = p[j - 1];
        p[j - 1] = p[j];
        p[j] = temp;
      }
    }
  }
}

void print_array3(char **p, long len) {
  for (int i = 0; i < len; ++i)
    printf("%s\n", p[i]);
}

void sort_pint_array() {
  char *p[] = {"bbb", "aaa", "ccc", "eee", "ddd"};
  long len = sizeof(p) / sizeof(p[0]);
  array_sort(p, len);
  print_array3(p, len);
}
