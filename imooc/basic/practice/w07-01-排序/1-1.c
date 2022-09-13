//
// Created by SlybootsLion on 2022/9/13.
//

#include <stdio.h>

void bubble_sort(int *p, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (p[j] > p[j + 1]) {
                p[j] ^= p[j + 1];
                p[j + 1] ^= p[j];
                p[j] ^= p[j + 1];
            }
        }
    }
}

void outpu(int *p, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d", p[i]);
    putchar('\n');
}

int main() {
    int a[5] = {50, 40, 30, 20, 10};
    int n = sizeof(a) / sizeof(a[0]);
    outpu(a, n);
    bubble_sort(a, n);
    outpu(a, n);
    return 0;
}
