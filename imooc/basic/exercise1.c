#include <stdio.h>

int main()
{
  int a, b, c, t;
  printf("input three number:");
  scanf("%d%d%d", &a, &b, &c);

  a > b ? (t = a, a = b, b = t) : a;
  a > c ? (t = a, a = c, c = t) : a;
  b > c ? (t = b, b = c, c = t) : a;

  printf("a=%d, c=%d, b=%d\n", a, b, c);

  return 0;
}

#include <stdio.h>

int main()
{
    int a, x, y, z;

    printf("input Three digits integer:\n");
    scanf("%d", &a);

    z = a % 100 % 10;
    y = a % 100 / 10;
    x = a / 100;
    printf("x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}
