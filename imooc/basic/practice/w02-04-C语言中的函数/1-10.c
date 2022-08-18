//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"

/*
int a[5];

// 1.设计一个input_array(),自己定义参数和返回值，输⼊数据存放到数组a中.
// 2.设计一个output_array()，自己定义参数和返回值，输出数组a的内容.
// 3.设计一个find_max(),自己定义参数和返回值，找到数组中的最大值，并返回给main函数输出。
*/

void input_array(int *arr, int len) {
    printf("input %d numbers:\n", len);
    for (int i = 0; i < len; ++i)
        scanf("%d", &arr[i]);
}

void output_array(int *arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int find_max(int *arr, int len) {
    int max_num = arr[0];
    for (int i = 1; i < len; ++i) {
        if (max_num < arr[i])
            max_num = arr[i];

    }
    return max_num;
}

int main() {
    int a[5];
    int len = sizeof(a) / sizeof(a[0]);
    input_array(a, len);
    output_array(a, len);
    int max_num = find_max(a, len);
    printf("max num is :%d\n", max_num);
    return 0;
}
