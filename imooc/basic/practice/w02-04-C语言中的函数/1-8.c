/*
1.main()函数定义4个变量，int a,b,max_value,sum.要求用户从键盘输入
  2个数据赋值给a和b 。

2.设计一个叫做calc_data()函数，自定义返回值和参数，要求该函数中
  求出a和b中的最大值，函数调用结束后，要求给main函数max_value存储的
  是两个数中较大的值。在求两个数的和，要求给main函数sunm存储的两个
  数据的和。

3.在main函数中打印max_value和sum的值。
*/

#include "stdio.h"

void calc_data(int a, int b, int *max_value, int *sum) {
    *max_value = a > b ? a : b;
    *sum = a + b;
}

int main() {
    int a, b, max_value, sum;

    printf("input 2 integer numbers:\n");
    scanf("%d%d", &a, &b);

    calc_data(a, b, &max_value, &sum);

    printf("max num is: %d, sum is %d\n", max_value, sum);

    return 0;
}
