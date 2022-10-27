#include "head.h"

void copy_string() {
  char str[] = "hello world";
  char buf[100];
//  copy_string1(str, buf);
//  copy_string2(str, buf);
  copy_string3(str, buf);
  printf("buf = %s\n", buf);
}

void reverse_string() {
  char str[] = "xideffa";
//  reverse_string1(str);
  reverse_string2(str);
  printf("str = %s\n", str);
}

void pointer_arguments() {
//  fun_arg_pointer_in();
  fun_arg_pointer_out();
}

int main() {
//  copy_string();
//  reverse_string();
  pointer_arguments();
  return 0;
}
