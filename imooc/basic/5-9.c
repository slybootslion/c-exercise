#include <stdio.h>

int howOld(int count)
{
  if (count <= 1)
    return 10;
  int age = howOld(count - 1);
  return age + 2;
}

int main()
{
  int age = howOld(5);
  printf("第5个人的年龄是%d岁", age);
  return 0;
}
