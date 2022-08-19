//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int calc(int a, int b, int (*pfun)(int, int)) {
    int result = pfun(a, b);
    return result;
}

int main() {
    int result = 0;
    result = calc(20, 20, add);
    printf("a + b = %d\n", result);

    result = calc(20, 10, sub);
    printf("a - b = %d\n", result);

    return 0;
}
