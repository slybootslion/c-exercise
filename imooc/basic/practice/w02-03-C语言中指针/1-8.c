#include <stdio.h>

/*
int a[5] = {10，20，30，40，50}；
int *p = a;
要求通过a,a[i]和p,p[i]四种不同的形式输出数组的内容
 */

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len; ++i) {
        printf("a[%d] = %d \t", i, a[i]);
        printf("p[%d] = %d \t", i, p[i]);
        printf("*(a + %d) = %d \t", i, *(a + i));
        printf("*(p + %d) = %d \n", i, *(p + i));
    }
    return 0;
}
