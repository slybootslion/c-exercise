#include <stdio.h>

/*
 定义一个int a[10][10]的数组，利用二维数组输出下列杨辉三角的图案.
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
… …
 * */

int main() {
    int arr[10][10] = {0};

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < i + 1; ++j)
            arr[i][j] = j == 0 ? 1 : arr[i - 1][j] + arr[i - 1][j - 1];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < i + 1; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}
