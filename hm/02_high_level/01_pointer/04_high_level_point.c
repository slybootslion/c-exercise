#include "head.h"

void allocate_space(char **p) {
  *p = (char *) malloc(100);
  strcpy(*p, "hello world");
}

void free_space(char **p) {
  if (p == NULL)
    return;
  if (*p != NULL) {
    free(*p);
    *p = NULL;
  }
}

void high_level_pointer() {
  char *p = NULL;
  allocate_space(&p);
  printf("%s\n", p);
  free_space(&p);

  if (p == NULL)
    printf("内存释放!\n");
}
