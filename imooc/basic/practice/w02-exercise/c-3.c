//
// Created by SlybootsLion on 2022/8/19.
//
/*
设计一个int str_to_int(char *str)函数，str为数字字符串，
要求把str数字字符串转换为整数返回
*/
#include <string.h>
#include "stdio.h"

char *input_str() {
    static char s[100];
    printf("input number string : \n");
    fgets(s, 100, stdin);
    return s;
}

int str_to_int(const char *str) {
    int num = 0;
    for (int i = 0; str[i] != '\n'; ++i)
    // like: num = num * 10 + str[i] - '0';
        num = num * 10 + str[i] - 48;
    return num;
}

int main() {
    char *s = input_str();
    int num = str_to_int(s);
    printf("number: %d\n", num);
    return 0;
}
