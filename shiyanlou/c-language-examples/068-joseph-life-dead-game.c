#include <stdio.h>

int main()
{
  int c = 0, i = 1, j = 0, a[30] = {0}, b[30] = {0};

  while (i <= 31)
  {
    if (i == 31)
      i = 1;
    else if (c == 15)
      break;
    else
    {
      if (b[i] != 0)
      {
        i++;
        continue;
      }
      else
      {
        j++;
        if (j != 9)
        {
          i++;
          continue;
        }
        else
        {
          b[i] = 1;
          a[i] = j;
          j = 0;
          printf("第%d号下穿了\n", i);
          i++;
          c++;
        }
      }
    }
  }

  return 0;
}
