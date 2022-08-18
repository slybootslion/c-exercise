//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"
#include "string.h"

// strcmp 字符串比较函数
int main() {
    char buf1[20];
    char buf2[20];
    int ret = 0;

    printf("please input string buf1: ");
    fgets(buf1, 20, stdin);

    printf("please input string buf2: ");
    fgets(buf2, 20, stdin);

    ret = strcmp(buf1, buf2);
    printf("ret = %d\n", ret);

    if (ret > 0) {
        printf("buf1 > buf2");
    } else if (ret == 0) {
        printf("buf1 = buf2");
    } else {
        printf("buf1 < buf2");
    }
    putchar('\n');

    return 0;
}
