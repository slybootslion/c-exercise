#include <stdio.h>

int main()
{
  int a = 100, b = 10;
  int *point_1, *point_2; //定义指向整型数据的指针变量 point_1,point_2
  point_1 = &a;           //把变量 a 的地址赋给指针变量 point_1
  point_2 = &b;

  printf("a=%d, b=%d\n", a, b);
  printf("%p, %p\n", point_1, point_2); //输出 a 和 b 在内存中的地址

  printf("point_1=%d, point_2=%d\n", *point_1, *point_2); //输出变量 a 和 b 的值
  return 0;
}
