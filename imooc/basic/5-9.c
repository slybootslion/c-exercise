#include <stdio.h>

int how_old(int count)
{
  if (count <= 1)
    return 10;
  int age = how_old(count - 1);
  return age + 2;
}

int main()
{
  int age = how_old(5);
  printf("第5个人的年龄是%d岁", age);
  return 0;
}
