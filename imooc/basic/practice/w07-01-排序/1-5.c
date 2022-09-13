//
// Created by SlybootsLion on 2022/9/13.
//

#include <stdio.h>

void direct_insert_sort(int *p, int plen) {
    for (int i = 0; i < plen; ++i) {
        if (p[i] < p[i - 1]) {
            int temp = p[i];
            int j = i - 1;
            for (; j >= 0 && temp < p[j]; j--) {
                p[j + 1] = p[j];
            }
            p[j + 1] = temp;
        }
    }
}

void output_array_info(int *p, int plen) {
    for (int i = 0; i < plen; ++i)
        printf("%d ", p[i]);
    putchar('\n');
}

int main() {
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    direct_insert_sort(a, n);
    output_array_info(a, n);
    return 0;
}
