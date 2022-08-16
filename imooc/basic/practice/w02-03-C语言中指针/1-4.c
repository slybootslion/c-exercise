#include <stdio.h>

int main() {
    double f = 3.14;
    void *p = &f;
    printf("%.2f\n", *(double *) p);
    return 0;
}
