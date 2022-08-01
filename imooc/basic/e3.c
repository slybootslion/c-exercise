#include <stdio.h>

int main()
{
    int value = 0;
    int a = 0;
    int b = 1;
    value = a && b;
    printf("%d\n", value); // 0
    value = a || b;
    printf("%d\n", value); // 1
    value = a++ && b++; // a = 1 b = 1 &&之后不执行
    printf("%d\n", value); // 0
    value = --a || b--; // a = 0 b = 0
    printf("%d\n", value); // 1
    value = (a + b) || (a - b);
    printf("%d\n", value); // 0
    value = (a * b) && (a + b);
    printf("%d\n", value); // 0
    value = !a;
    printf("%d\n", value); // 1
    printf("%d,%d,%d\n", a, b, value); // 0 0 1
    return 0;
}
