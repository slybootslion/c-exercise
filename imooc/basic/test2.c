#include <stdio.h>

#define DEBUG

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int i = 10;
    int *p = a;

#ifndef DEBUG
    for (i = 0; i < 5; ++i)
        printf("a[%d] = %d\n", i, a[i]);
#else
    for (i = 0; i < 5; i++)
        printf("p[%d] = %d\n", i, p[i]);
#endif

    return 0;
}
