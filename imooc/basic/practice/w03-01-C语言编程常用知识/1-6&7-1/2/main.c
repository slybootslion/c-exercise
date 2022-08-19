//
// Created by SlybootsLion on 2022/8/19.
//
#include "head.h"

int main () {
    int max_value = 0;
    printf("please input two number : ");
    scanf("%d%d", &m, &n);

    max_value = find_max();
    printf("max value is: %d\n", max_value);

    return 0;
}
