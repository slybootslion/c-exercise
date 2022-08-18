//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"
#include "string.h"

int main() {
    char buf[100];
    printf("please input string:\n");
    scanf("%s", buf);

    printf("strlen(buf) = %lu\n", strlen(buf));
    printf("sizeof(buf) = %ld\n", sizeof(buf));

    return 0;
}
