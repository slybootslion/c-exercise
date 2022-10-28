#include "head.h"

void change_pointer() {
  char *p = (char *) malloc(100);
  char buf[] = "hello world";
  unsigned long len = strlen(buf);
  /*
   指针叠加会不断改变指针指向，不能这样写，free时候会报错。
   for (int i = 0; i < len; ++i) {
    *p = buf[i];
    p++;
  }
  free(p);
  */
  char *pt = p;
  for (int i = 0; i < len; ++i) {
    *pt = buf[i];
    pt++;
  }
  printf("%s\n", p);
  free(p);
}
