#include <stdio.h>

//
// Created by SlybootsLion on 2022/8/19.
//
struct student {
    char a;
    int b;
    short c;
};

union stu {
    char a;
    int b;
    short c;
};

int main() {
    struct student st;
    union stu su;

    printf("sizeof(struct) : %ld \n", sizeof(st));
    printf("sizeof(union) : %ld \n", sizeof(su));

    printf("&a : %p\n", &su.a);
    printf("&b : %p\n", &su.b);
    printf("&c : %p\n", &su.c);

    su.b = 0x12345678;

    printf("a = %#x\n", su.a);
    printf("b = %#x\n", su.b);
    printf("c = %#x\n", su.c);

    return 0;
}
