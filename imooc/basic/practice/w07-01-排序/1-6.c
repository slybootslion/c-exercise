#include <stdio.h>

void shell_sort(int *p, int plen) {
    for (int k = plen / 2; k >= 1; k = k / 2) {
        for (int i = k; i < plen; i++) {
            int temp = p[i];
            int j = i - k;
            for (; j >= 0 && p[j] > temp; j = j - k)
                p[j + k] = p[j];
            p[j + k] = temp;
        }
    }
}

void output_array(int *p, int plen) {
    for (int i = 0; i < plen; ++i)
        printf("%d ", p[i]);
    printf("\n");
}

int main() {
    int a[] = {9, 1, 2, 5, 7, 4, 3, 6};
    int len = sizeof(a) / sizeof(a[0]);
    output_array(a, len);
    shell_sort(a, len);
    output_array(a, len);
    return 0;
}
