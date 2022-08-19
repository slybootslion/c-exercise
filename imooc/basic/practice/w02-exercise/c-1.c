//
// Created by SlybootsLion on 2022/8/18.
//

/*
1. int main()函数中定义一个int a[5]数组。
2. 设计一个input_data()函数,自定义参数和返回值，输入5个数据到数组中
3. 设计一个count_data()函数,自定义参数和返回值，统计输入的正数的个数和正数之和。
4. int main()中调用上述函数。
 * */
#include <stdio.h>

void input_data(int *a, int len) {
    printf("input 5 integer number:\n");
    for (int i = 0; i < len; ++i)
        scanf("%d", &a[i]);
}

void count_data(const int *a, int len) {
    int count = 0, sum = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] > 0) {
            sum += a[i];
            count++;
        }
    }
    printf("sum: %d, count: %d\n", sum, count);
}

int main() {
    int a[5] = {0};
    int len = sizeof(a) / sizeof(a[0]);
    input_data(a, len);
    count_data(a, len);
    return 0;
}
