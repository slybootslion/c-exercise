#include "stdio.h"

int do_calc(const int x, const int y) {
    int sum = 0;
    printf("x = %d y = %d\n", x, y);
    sum = x + y;
    return sum;
}

int main() {
    int a = 0, b = 0, t = 0;
    printf("please input two data: ");
    scanf("%d%d", &a, &b);

    t = do_calc(a, b);
    printf("a + b = %d\n", t);

    t = t * 100 - 8;
    printf("expression result = %d\n", t);

    return 0;
}
