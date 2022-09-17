//
// Created by SlybootsLion on 2022/9/17.
//

#include <stdio.h>
#include <stdarg.h>
void Printlnf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)

#define PRINT_INT(value) PRINTLNF(#value": %d", value);

#define PRINTLNF_CODENUM(format, ...) printf("("__FILE__":%d) %s : "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

int main() {

  Printlnf("this is string");

  int a = 3;
  PRINTLNF("hello world! %d", a);
  PRINTLNF("hello world!");
  PRINT_INT(a);

  PRINTLNF_CODENUM("take code file info -- a is: %d", a);
  return 0;
}
