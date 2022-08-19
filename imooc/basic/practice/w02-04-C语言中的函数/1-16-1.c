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

int main() {
    int ret = 0;
    ret = add(10, 20);
    printf("a + b = %d\n", ret);

    printf("add = %p\n", add);
    printf("===============\n");

    // 数据类型 (*指针变量名)(类型1  参数1，类型2 参数2...);
    int (*funp)(int, int) = add;
    printf("funp = %p\n", funp);

    ret = funp(10, 20);
    printf("a + b = %d\n", ret);

    funp = sub;
    ret = funp(10, 20);
    printf("a - b = %d\n", ret);

    return 0;
}
