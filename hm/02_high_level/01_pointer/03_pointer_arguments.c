#include "head.h"

/*
 指针做函数参数，具备输入和输出特性：
    输入：主调函数分配内存
	输出：被调用函数分配内存
 * */

void fun_in(char *p) {
  strcpy(p, "abcdefg");
}

void fun_arg_pointer_in() {
  char buf[100] = {0};
  fun_in(buf);
  printf("buf = %s\n", buf);
}

void fun_out(char **p, int *len) {
  char *tmp = (char *) malloc(100);
  if (tmp == NULL) {
    return;
  }
  strcpy(tmp, "gfedcba");
  *p = tmp;
  *len = strlen(tmp);
}

void fun_arg_pointer_out() {
  char *p = NULL;
  int len = 0;
  fun_out(&p, &len);
  if (p != NULL)
    printf("p = %s, len = %d\n", p, len);
}
