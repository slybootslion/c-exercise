#include <stdio.h>

/*
int a[8] = {10,15,27,33,78,65};
(1)要求用户输出上述数组的内容
(2)要求求上述数组中奇数的和。
(3)求上述数据中所有元素(8个)的平均值,省略小数,输出整数。
 * */
int main() {
    int a[8] = {10, 15, 27, 33, 78, 65};
    int odd_count = 0, count = 0;
    for (int i = 0; i < 8; ++i) {
        if (i % 2)
            odd_count += a[i];
        count += a[i];
    }
    printf("odd sum is %d\n", odd_count);
    printf("ave is %d\n", count / 8);
    return 0;
}
