//
// Created by SlybootsLion on 2022/9/13.
//
#include <stdio.h>

void select(unsigned char *str, int len) {
    for (int i = 0; str[i] != '\0'; ++i) {
        int k = i;
        for (int j = k + 1; j < len; ++j) {
            if (str[j] < str[k])
                k = j;
        }
        if (k != i) {
            str[i] ^= str[k];
            str[k] ^= str[i];
            str[i] ^= str[k];
        }
    }
}

int main() {
    unsigned char str[] = "decba";
    printf("%s \n", str);
    select(str, 5);
    printf("%s \n", str);
    return 0;
}
