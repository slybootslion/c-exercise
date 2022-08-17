#include <stdio.h>

int main() {
    int *p = NULL;
    char **p_char = (char **) &p;
    short **p_short = (short **) &p;
    int **p_int = (int **) &p;

    printf("sizeof(p_char) = %ld\n", sizeof(p_char));
    printf("sizeof(p_short) = %ld\n", sizeof(p_short));
    printf("sizeof(p_int) = %ld\n", sizeof(p_int));

    printf("p_char = %p\n", p_char);
    printf("p_short = %p\n", p_short);
    printf("p_int = %p\n", p_int);

    printf("=================================\n");

    p_char++;
    p_short++;
    p_int++;

    printf("p_char = %p\n", p_char);
    printf("p_short = %p\n", p_short);
    printf("p_int = %p\n", p_int);

    return 0;
}
