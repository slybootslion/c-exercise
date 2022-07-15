// 定义一个函数 copy_string 用来实现字符串复制的功能，在主函数中调用此函数，函数的形参和实参可以分别用字符数组名或字符指针变量。分别编程，以供分析比较。

#include <stdio.h>

int main()
{
  void copy_string(char from[], char to[]);
  char a[] = "I am a teacher";
  char b[] = "You are a programmer";

  printf("string a=%s\nstring b=%s\n", a, b);
  printf("copy string a to string b:\n");
  copy_string(a, b);
  printf("\nstring a=%s\nstring b=%s\n", a, b);

  return 0;
}

void copy_string(char from[], char to[])
{
  int i = 0;
  while (from[i] != '\0')
  {
    to[i] = from[i];
    i++;
  }
  to[i] = '\0';
}
