/*
 1.设计一个void do_sum()函数，要求函数内部无参数和返回值，内部定义一个变量int m,
 要求用户从键盘输入一个数据赋值给m。
 判断m的值,若是m为奇数，输出1 + 3 + 5 + 7 + 9 +...+m的和.
          若是m为偶数，输出0 + 2 + 4 + 6 + 8 +...+m的和.
2.设计一个void do_Result()函数，要求函数内部定义int a,b两个变量，然后从键盘输入
  2个整数赋值给a,b，并输出(a + b) / 2的值。
 * */

#include "stdio.h"

void do_sum() {
    int m, count = 0;
    printf("input integer number:\n");
    scanf("%d", &m);
    while (m >= 1) {
        count += m;
        m -= 2;
    }
    printf("count is %d\n", count);
}

void do_result(int a, int b) {
    printf("input 2 integer:\n");
    scanf("%d%d", &a, &b);
    printf("(a + b) / 2 = %d\n", (a + b) / 2);
}

int main() {
    do_sum();
    int a, b;
    do_result(a, b);
    return 0;
}
