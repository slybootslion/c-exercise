#include <stdio.h>

int main()
{

  char x, y, z;

  printf("please input three character : ");
  scanf("%c%c%c", &x, &y, &z);

  printf("x = %c : %d\n", x, x);
  printf("y = %c : %d\n", y, y);
  printf("z = %c : %d\n", z, z);
  return 0;
}
