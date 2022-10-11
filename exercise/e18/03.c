#include "head.h"

// 兔子问题:1,1,2,3,5,8,13,21...

int main() {
  long f1 = 1, f2 = 1;
  for (int i = 1; i <= 20; ++i) {
    printf("%12ld %12ld", f1, f2);
    f1 += f2;
    f2 += f1;
  }
  return 0;
}
