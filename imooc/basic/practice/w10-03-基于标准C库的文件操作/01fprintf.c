#include <stdio.h>

int main(void) {

  fprintf(stdout, "Hello,Linux io");
  fflush(stdout);// 强制刷新缓冲区
  putchar('\n');
  return 0;
}
