#include <stdio.h>

int main() {
    int a[5] = {10, 20, 31, 32, 40};
    printf("%d\n", *(((char *) (&a + 1)) - 3) - 2);
    return 0;
}
