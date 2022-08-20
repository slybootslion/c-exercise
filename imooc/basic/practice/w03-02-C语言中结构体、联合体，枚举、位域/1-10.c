//
// Created by SlybootsLion on 2022/8/20.
//
#include <stdio.h>

/*
设计一个枚举类型，枚举颜色 ,输出每种颜色代表的值
enum COLOR
{
        red = 1,
        green = 2,
        yellow,
        blue,
        black,
};

int main()
{
        int  col;
        //1.要求用户从键盘输入数据存放到col中。

        //根据col输入的值，来输出对应的颜色.
}
* */

enum COLOR {
    red = 1,
    green,
    yellow,
    blue,
    black,
};

int main() {
    int col;
    printf("input integer number select color:\n");
    scanf("%d", &col);

    switch (col) {
        case red:
            printf("selected color is red\n");
            break;
        case green:
            printf("selected color is green\n");
            break;
        case yellow:
            printf("selected color is yellow\n");
            break;
        case blue:
            printf("selected color is blue\n");
            break;
        case black:
            printf("selected color is black\n");
            break;
        default:
            printf("no exist\n");
    }

    return 0;
}
