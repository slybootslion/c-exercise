/*
int a[2][3] = {10,20,30,40,50,60};
int (*p)[3] = a;
要求通过多种方式输出a数组中的数据
 * */
#include "stdio.h"

int main() {
    int a[2][3] = {10, 20, 30, 40, 50, 60};
    int (*p)[3] = a;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); ++j) {
            printf("a[%d][%d] = %d\t", i, j, a[i][j]);
            printf("*(a[%d] + %d) = %d\t", i, j, *(a[i] + j));
            printf("*(*(a + %d) + %d) = %d\t", i, j, *(*(a + i) + j));
            printf("p[%d][%d] = %d\t", i, j, p[i][j]);
            printf("*(p[%d] + %d) = %d\t", i, j, *(p[i] + j));
            printf("*(*(p + %d) + %d) = %d\n", i, j, *(*(p + i) + j));
        }
    }

    return 0;
}

