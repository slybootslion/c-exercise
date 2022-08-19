#include <stdio.h>

//
// Created by SlybootsLion on 2022/8/19.
//
struct student {
    int id;
    short score;
    char name[5];
};
//计算出上述类型的大小，并打印输出

int main() {
    struct student st;
/*
     int 4
     short 2
     char[5] 1 * 5
     [
        int    int    int    int
        short  short  char   char
        char   char   char   ***
     ]
*/
    printf("sizeof(st) = %ld\n", sizeof(st)); // 12
    return 0;
}
