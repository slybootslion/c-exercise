//
// Created by SlybootsLion on 2022/9/13.
//
#include <stdio.h>

void select_sort(int *p, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int k = i;
        for (int j = k + 1; j < n; ++j) {
            if (p[j] < p[k])
                k = j;
        }
        if (k != i) {
            p[i] ^= p[k];
            p[k] ^= p[i];
            p[i] ^= p[k];
        }
    }
}

void output(int *p, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", p[i]);
    putchar('\n');
}

int main() {
    int a[5] = {50, 40, 30, 20, 10};
    int n = sizeof(a) / sizeof(a[0]);
    output(a, n);
    select_sort(a, n);
    output(a, n);
    return 0;
}
