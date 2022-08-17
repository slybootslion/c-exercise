#include <stdio.h>

int main() {
    int a[3];
    int b[3][2];

    printf("a  = %#x\n", *a);//int *
    printf("&a = %#x\n", &a);//int (*)[3]
    printf("b  = %#x\n", b);//int (*)[2]
    printf("b[0] = %#x\n", b[0]);//int *

    printf("--------------------\n");

    printf("a  +   1 = %#x\n", a + 1);//int *       -> 移动1个元素 4字节
    printf("&a +   1 = %#x\n", &a + 1);//int (*)[3] -> 移动3个元素 12字节
    printf("b  +   1 = %#x\n", b + 1);//int (*)[2]  -> 移动2个元素 8字节
    printf("b[0] + 1 = %#x\n", b[0] + 1);//int *    -> 移动1个元素 4自己

    return 0;
}
