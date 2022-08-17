#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    int *p[3] = {&a, &b, &c};
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);
    printf("========================\n");

    int n = sizeof(p) / sizeof(p[0]);

    for (int i = 0; i < n; ++i)
        printf("p[%d] = %p\n", i, p[i]);
    printf("========================\n");
    for (int i = 0; i < n; ++i)
        printf("*p[%d] = %d\n", i, *p[i]);

    return 0;
}
