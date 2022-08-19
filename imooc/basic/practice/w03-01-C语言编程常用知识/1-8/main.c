//
// Created by SlybootsLion on 2022/8/19.
//
/*
(1)自己设计一个calc.c head.h main.c实现多文件编程
(2)calc.c中自己设计add(),sub(),mul(),div()等四个函数
(3)main.c中包含head.h头文件,然后调用上面的函数，并输出结果
 * */

#include "head.h"

int main() {
    printf("input 2 integer number: \n");
    scanf("%d%d", &a, &b);

    int res;
    res = add(a, b);
    printf("add() = %d\n", res);
    res = sub(a, b);
    printf("sub() = %d\n", res);
    res = mul(a, b);
    printf("mul() = %d\n", res);
    res = div(a, b);
    printf("div() = %d\n", res);

    return 0;
}
