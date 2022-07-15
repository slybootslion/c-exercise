// 编写一个程序，输入月份号，输出该月份号的英文名称。例如输入 8，则输出 “August”，要求用指针数组处理。
#include <stdio.h>

int main()
{
  int num;

  printf("enter 1-12 number:");
  scanf("%d", &num);

  if (num > 12 || num < 1)
  {
    printf("error!");
    return 0;
  }
  //初始化月份
  const char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  // printf("%s", month[num]);
  printf("%s", *(month + num - 1));

  return 0;
}
