//
// Created by SlybootsLion on 2022/8/20.
//

#include <stdio.h>

struct bit {
    unsigned int a: 6;
    unsigned int b: 12;
    unsigned int c: 4;
} bt;

// 求sizeof(bt)的大小。

/*
 int a: 6    a  a  a  a  a  a  |  |
 int b: 12   b  b  b  b  b  b  b  b
             b  b  b  b  |  |  |  |
 int c: 4    c  c  c  c  |  |  |  |
 * */

int main() {
    printf("%ld\n", sizeof(bt)); // 4
    return 0;
}
