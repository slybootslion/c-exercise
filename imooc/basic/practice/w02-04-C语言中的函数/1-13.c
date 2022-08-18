//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"
#include "string.h"

/*
 char buf[] = "I Love China";

(1)设计一个count_uppercase_character()函数，自己定义参数和返回值，要求
   统计上述数组中大写字符的个数。
(2)调用自己设计的函数，并输出。

 * */

int count_uppercase_character(char *str) {
    int count = 0;
    unsigned long len = strlen(str);
    for (int i = 0; i < len; ++i) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z')
            count++;
    }
    return count;
}

int main() {
    char buf[] = "I Love China";

    int count = count_uppercase_character(buf);
    printf("uppercase char count is: %d \n", count);

    return 0;
}
