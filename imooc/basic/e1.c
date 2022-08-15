#include <stdio.h>

void input_data(int *arr, int len) {
    printf("input 5 integer number:\n");
    for (int i = 0; i < len; ++i)
        scanf("%d", &arr[i]);
}

void count_data(const int *arr, int len, int *count, int *sum) {
    for (int i = 0; i < len; ++i) {
        if (arr[i] > 0) {
            (*count)++;
            *sum += arr[i];
        }
    }
}

int main() {
    int a[5] = {0};
    int len = sizeof(a) / sizeof(a[0]);
    int count = 0, sum = 0;

    input_data(a, len);
    count_data(a, len, &count, &sum);
    printf("正数的个数：%d，正数之和：%d\n", count, sum);

    return 0;
}
