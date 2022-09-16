#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...) {
  va_list args;
  va_start(args, arg_count);
  for (int i = 0; i < arg_count; ++i) {
    int arg = va_arg(args, int);
    printf("%d: %d\n", i, arg);
  }
  va_end(args);
}

int main() {
  HandleVarargs(5, 1, 2, 3, 4, 5);
  return 0;
}
