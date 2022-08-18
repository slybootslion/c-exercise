#include "stdio.h"

void input_array(int *p, const int plen) {
    printf("input %d data: \n", plen);
    for (int i = 0; i < plen; ++i)
        scanf("%d", &p[i]);
}

void output_array(int *p, const int plen) {
    for (int i = 0; i < plen; ++i)
        printf("%d\t", p[i]);
    printf("\n");
}

int main() {
    int a[5];
    int len = sizeof(a) / sizeof(a[0]);

    input_array(a, len);
    output_array(a, len);

    return 0;
}
