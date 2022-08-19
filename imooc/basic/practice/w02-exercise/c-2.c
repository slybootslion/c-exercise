//
// Created by SlybootsLion on 2022/8/19.
//
/*
1. int main()函数中定义一个int a[5]数组。
2. 设计一个input_data()函数,自定义参数和返回值，输入5个数据到数组中
3. 设计一个reverse_data()函数,自定义参数和返回值，把5个数据逆序存储。
4. 设计一个output_data()函数,自定义参数和返回值，输出数组中的数据
5. int main()中调用上述函数。
*/

#include "stdio.h"

void input_data(int *a, int len) {
    printf("input %d integer number:\n", len);
    for (int i = 0; i < len; ++i)
        scanf("%d", &a[i]);
}

void reverse_data(int *a, int len) {
    for (int i = 0; i < len / 2; ++i) {
        int t = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = t;
    }
}

void output_data(int *a, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d\t", a[i]);
    putchar('\n');
}

int main() {
    int a[5], len = sizeof(a) / sizeof(a[0]);
    input_data(a, len);
    reverse_data(a, len);
    output_data(a, len);
    return 0;
}
