//
// Created by SlybootsLion on 2022/8/19.
//
/*
写一个宏获取两个数中较大的值。
#define  MAX_VALUE(x,y)   xxx
例如:
int a = 10;
int b = 20;
int max;
*/

#include <stdio.h>

#define MAX_VALUE(x, y) x > y ? x : y;

int main() {
    int a = 10, b = 20;
    int max = MAX_VALUE(a, b);
    printf("max number is: %d \n", max);
    return 0;
}
