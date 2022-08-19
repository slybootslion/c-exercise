//
// Created by SlybootsLion on 2022/8/18.
//
# include "stdio.h"

int cutpie(int n) {
    int sum = 0;
    if (n == 0)
        return 1;
    sum = cutpie(n - 1) + n;
    return sum;
}

int main () {
    int n = 0, num = 0;
    printf("please input you want to cut knife_number: \n");
    scanf("%d", &n);

    num = cutpie(n);
    printf("num = %d\n", num);

    return 0;
}
