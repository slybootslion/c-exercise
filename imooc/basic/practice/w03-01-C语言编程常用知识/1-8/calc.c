//
// Created by SlybootsLion on 2022/8/19.
//
#include "head.h"

int a, b;

int add() {
    return a + b;
}

int sub() {
    return a - b;
}

int mul() {
    return a * b;
}

int div() {
    if (b == 0)
        printf("Division by zero error!\n");
    return a / b;
}
