//
// Created by SlybootsLion on 2022/8/18.
//
/*
 (1)要求大家是设计一个design_arary()函数,自己定义返回值和参数。
  要求design_array()函数中定义一个,static char a[100] = {0};,然后
  把数组首地址和长度返回。

(2)设计一个input_array()函数，自定义返回和参数，要求用户从键盘
   输入任意的字符串，存放到a数组中

(3)设计一个output_array()函数，要求输出a数组中的每个一字符，
  以空格作为区分. w u h a n s h a n g h a i

(4)设计一个cout_space()函数，自定义返回和参数，要求用户统计数组a中用户
  输入的空格个数，并返回值给main函数。

(5)main（）函数调用以上函数，并输出空格个数。
 * */

#include "stdio.h"

char *design_array(unsigned long *len) {
    static char a[100] = {0};
    *len = sizeof(a) / sizeof(a[0]);
    return a;
}

void input_array(char *a) {
    printf("input string: ");
    fgets(a, 100, stdin);
}

void output_array(const char *a) {
    for (int i = 0; a[i] != '\0'; ++i)
        printf("%c ", a[i]);
    printf("\n");
}

int count_space(const char *a) {
    int count = 0;
    for (int i = 0; a[i] != '\0'; ++i) {
        char c = a[i];
        if (c == ' ')
            count++;
    }
    return count;
}

int main() {
    unsigned long len;
    char *a = design_array(&len);
    input_array(a);
    output_array(a);
    int c = count_space(a);
    printf("space count is : %d\n", c);
    return 0;
}
