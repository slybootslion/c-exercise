#include "stdio.h"

void change_value(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void do_calc(int x, int y, int *m, int *n) {
    int sum1 = 0, sum2 = 0;
    sum1 = x + y;
    sum2 = x - y;

    *m = sum1;
    *n = sum2;
}

int main() {
    int a = 0, b = 0, ret1 = 0, ret2 = 0, t = 0;

    printf("input 2 data:\n");
    scanf("%d%d", &a, &b);


    printf("a = %d b = %d\n", a, b);

    change_value(&a, &b);
    printf("changed: a = %d, b = %d\n", a, b);

    do_calc(a, b, &ret1, &ret2);

    printf("a + b = %d\n", ret1);
    printf("a - b = %d\n", ret2);

    return 0;
}
