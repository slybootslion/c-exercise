#include <stdio.h>

void input_data(int *arr, int len) {
    printf("input 5 integer number:\n");
    for (int i = 0; i < len; ++i)
        scanf("%d", &arr[i]);
}

void reverse_data(int *arr, int len) {
    for (int i = 0; i < len / 2; ++i) {
        int p1 = i, p2 = len - (i + 1);
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
    }
}

void output_data(int *arr, int len) {
    for (int i = 0; i < len; ++i)
        printf("%d  ", arr[i]);
}

int main() {
    int a[5] = {0};
    int len = sizeof(a) / sizeof(a[0]);
    input_data(a, len);
    reverse_data(a, len);
    output_data(a, len);
    printf("\n");
    return 0;
}
