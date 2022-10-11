#include "head.h"

int main() {
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j <= i; ++j)
      printf("%d * %d = %-3d", j, i, j * i);
    putchar('\n');
  }
}
