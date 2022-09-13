//
// Created by SlybootsLion on 2022/9/13.
//
#include <stdio.h>

void swap_data(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void heap_adjust(int *arr, int start, int end) {
    int father_node = start;
    int son_node = father_node * 2 + 1;

    while (son_node <= end) {
        if (son_node + 1 <= end && arr[son_node] < arr[son_node + 1])
            son_node++;
        if (arr[father_node] > arr[son_node])
            return;
        else {
            swap_data(&arr[father_node], &arr[son_node]);
            father_node = son_node;
            son_node = father_node * 2 + 1;
        }
    }
}

void heap_sort(int *arr, int len) {
    for (int i = len / 2; i >= 0; --i)
        heap_adjust(arr, i, len - 1);

    for (int i = len - 1; i > 0; --i) {
        swap_data(&arr[0], &arr[i]);
        heap_adjust(arr, 0, i - 1);
    }
}

void print_array(int a[], int plen) {
    for (int i = 0; i < plen; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {16, 7, 3, 20, 17, 8};
    int len = sizeof(a) / sizeof(a[0]);
    heap_sort(a, len);
    print_array(a, len);
    return 0;
}
