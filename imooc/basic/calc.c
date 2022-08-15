#include "head.h"

int m;
int n;

int add() {
    return m + n;
}

int sub() {
    return m - n;
}

int mul() {
    return m * n;
}

int div() {
    if (n == 0)
        printf("Division by zero error!\n");
    return m / n;
}
