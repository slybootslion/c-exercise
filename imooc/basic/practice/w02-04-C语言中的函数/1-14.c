//
// Created by SlybootsLion on 2022/8/18.
//
#include "stdio.h"

int *design_array(int *plen) {
    static int a[] = {100, 200, 300, 400, 500};
    int len = sizeof(a) / sizeof(a[0]);
    *plen = len;
    return a;
}

void output(int *p, int plen) {
    int i = 0;
    for (i = 0; i < plen; i++)
        printf("%d ", p[i]);
    putchar('\n');
}

int main() {
    int *p = NULL;
    int num = 0;
    p = design_array(&num);
    output(p, num);
    return 0;
}
