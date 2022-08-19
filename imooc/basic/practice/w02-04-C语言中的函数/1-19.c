//
// Created by SlybootsLion on 2022/8/18.
//
/*
练习: 要求大家用递归函数写一个5！

解析: 5!指的是求5的阶乘，即求5 * 4 * 3 * 2 * 1的值
       要求用递归函数实现。
*/
#include "stdio.h"

int factorial(int n) {
    if (n == 1) return 1;
    int res = factorial(n - 1) * n;
    return res;
}

int main() {
    int r = factorial(5);
    printf("5! = %d\n", r);
    return 0;
}
