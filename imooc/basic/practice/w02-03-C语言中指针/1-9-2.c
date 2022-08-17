#include <stdio.h>

int main() {
    int a[5] = {10, 11, 12, 13, 14};

    int *p = a;
    int **q = &p;

    printf("a[3] = %d\n", a[3]);
    printf("*(a + 3) = %d\n", *(a + 3));
    printf("*(p + 3) = %d\n", *(p + 3));
    printf("p[3] = %d\n", p[3]);

    printf("================\n");

    printf("*(*q + 3) = %d\n", *(*q + 3));
    printf("(*q)[3] = %d\n", (*q)[3]);

    return 0;
}
