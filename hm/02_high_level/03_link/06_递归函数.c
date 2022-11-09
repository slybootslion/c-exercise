#include "head.h"

void revers_handler(char *p) {
  if (*p == '\0')
    return;
  revers_handler(p + 1);
  putchar(*p);
}

void revers_string() {
  char *str = "abcde";
  revers_handler(str);
  putchar('\n');
}

int fibonacci(int pos) {
  if (pos < 2)
    return pos;
  return fibonacci(pos - 1) + fibonacci(pos - 2);
}

void recursion_exercise() {
//  revers_string();
  int res = fibonacci(15);
  printf("fibonacci(15) = %d\n", res);
}
