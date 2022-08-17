#include <stdio.h>

int main() {
    int a = 100, b = 200, c = 300;
    int *t[] = {&a, &b, &c, NULL};
    int **q = t;

    for (int i = 0; t[i] != NULL; ++i) {
        printf("%d\t", *t[i]);
        printf("%d\t", *(*(t + i)));
        printf("%d\t", *(*(q + i)));
        printf("%d\n", *q[i]);
    }
    printf("\n");

    return 0;
}
