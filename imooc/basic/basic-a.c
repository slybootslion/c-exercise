#include <stdio.h>

int main() {
    int a[2][3] = {10, 20, 30, 40, 50, 60};
    int (*p)[3] = a;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) {
            printf("a[%d][%d] = %d      ", i, j, a[i][j]);
            printf("*(a[%d] + %d) = %d      ", i, j, *(a[i] + j));
            printf("*(*(a + [%d]) + %d) = %d    ", i, j, *(*(a + i) + j));
            printf("p[%d][%d] = %d      ", i, j, p[i][j]);
            printf("*(p[%d] + %d) = %d      ", i, j, *(p[i] + j));
            printf("*(*(p + %d) + %d) = %d\n", i, j, *(*(p + i) + j));
        }

    return 0;
}
