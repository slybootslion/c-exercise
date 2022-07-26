#include <stdio.h>

int main()
{
  int x = 10, y = 20;
  int z = 0;

  z = (++x) + (y++);
  printf("z = %d\n", z); // 31

  z = (--x) + (y++);
  printf("z = %d\n", z); // 31

  z = (++x) + (--y);
  printf("z = %d\n", z); // 32

  printf("x = %d y = %d\n", x, y); // 11 21
  return 0;
}
