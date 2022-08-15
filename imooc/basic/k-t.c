#include <stdio.h>

enum COLOR {
    red = 1,
    green = 2,
    yellow,
    blue,
    black,
};


int main() {
    int col;
    printf("input a number[1-5]:\n");
    scanf("%d", &col);

    switch (col) {
        case red:
            printf("color is red\n");
            break;
        case green:
            printf("color is green\n");
            break;
        case yellow:
            printf("color is yellow\n");
            break;
        case blue:
            printf("color is blue\n");
            break;
        case black:
            printf("color is black\n");
            break;
        default:
            printf("number is wrong\n");
    }

    return 0;
}
