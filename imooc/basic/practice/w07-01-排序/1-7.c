//
// Created by SlybootsLion on 2022/9/13.
//

#include <stdio.h>

void quick_sort(int a[], int low, int high) {
    int i = low, j = high, key = a[low];
    while (i < j) {
        while (i < j && a[j] >= key)
            j--;
        if (i < j)
            a[i] = a[j];
        while (i < j && a[i] <= key)
            i++;
        if (i < j)
            a[j] = a[i];
    }
    a[i] = key;
    if (j - 1 > low)
        quick_sort(a, low, j - 1);
    if (i + 1 < high)
        quick_sort(a, i + 1, high);
}

void printf_array(int a[], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", a[i]);
    putchar('\n');
}

int main() {
    int a[] = {50, 36, 66, 76, 36, 12, 25, 95};
    int low = 0;
    int high = sizeof(a) / sizeof(a[0]) - 1;
    printf_array(a, high + 1);
    quick_sort(a, low, high);
    printf_array(a, high + 1);
    return 0;
}
