#include "head.h"

char **create_allocate_memory(int n) {
  char **temp = (char **) malloc(sizeof(char *) * n);
  for (int i = 0; i < n; ++i) {
    temp[i] = malloc(sizeof(char) * 30);
    sprintf(temp[i], "%2d_hello_world", i + 1);
  }
  return temp;
}

void array_print(char **p, int len) {
  for (int i = 0; i < len; ++i)
    printf("%s\n", p[i]);
  printf("\n");
}

void free_memory(char **p, int len) {
  for (int i = 0; i < len; ++i) {
    free(p[i]);
    p[i] = NULL;
  }
  free(p);
}

void allocate_memory() {
  int n = 10;
  char **p = create_allocate_memory(n);
  array_print(p, n);
  free_memory(p, n);
}
