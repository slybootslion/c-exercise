#include <stdio.h>

int main()
{
  int x, y;
  float b;
  double c;

  printf("place input two int data:");
  scanf("%d%d", &x, &y);
  printf("x=%d y=%d\n", x, y);

  printf("place input two float data:");
  scanf("%f%lf", &b, &c);
  printf("b = %f c = %lf\n", b, c);

  return 0;
}
