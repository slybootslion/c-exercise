//
// Created by SlybootsLion on 2022/9/13.
//

#include <stdio.h>

void bubble(unsigned char *str, int len) {
    for (int i = 0; str[i] != '\0'; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                str[j] ^= str[j + 1];
                str[j + 1] ^= str[j];
                str[j] ^= str[j + 1];
            }
        }
    }
}

int main() {
    unsigned char str[] = "decba";
    printf("%s \n", str);
    bubble(str, 5);
    printf("%s \n", str);
    return 0;
}
