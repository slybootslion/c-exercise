#include "head.h"

int main() {
    char a = -3;
    int b = a;
    unsigned int c = b;

    printf("a = %c b = %d c = %d\n", a, b, c); // -3 -3 253

    return 0;
}
