#include <stdio.h>

int main()
{
  for (int i = 0; i <= 9; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      printf("%dx%d=%d ", j, i, j * i);
    }
    printf("\n");
  }

  return 0;
}
