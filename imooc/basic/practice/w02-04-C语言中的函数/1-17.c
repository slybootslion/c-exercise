//
// Created by SlybootsLion on 2022/8/18.
//
/*
1. 设计一个int find_max(int x,int y)函数，要求返回两个数中较大的值
2. 设计一个int find_min(int x,int y)函数，要求返回两个数中较小的值
3. 设计一个int get_result(int x,int y,int (*pfun)(int ,int))函数，内部调用pfun函数,
   x,y当作pfun的参数，返回对应的结果。
4. main函数调用上述函数，输出结果
 * */

#include "stdio.h"

int find_max(int x, int y) {
    return x > y ? x : y;
}

int find_min(int x, int y) {
    return x > y ? y : x;
}

int get_result(int x, int y, int (*pfun)(int, int)) {
    return pfun(x, y);
}

int main() {
    int x, y;

    printf("input 2 integer number: \n");
    scanf("%d%d", &x, &y);

    int min = get_result(x, y, find_min);
    int max = get_result(x, y, find_max);

    printf("min: %d\n", min);
    printf("max: %d\n", max);

    return 0;
}
