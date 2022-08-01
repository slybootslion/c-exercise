#include <stdio.h>

int main()
{
    char a, b;
    printf("input 2 char data:");
    scanf("%c%c", &a, &b);
    printf("a < b : %d\n", a < b);
    printf("a > b : %d\n", a > b);
    printf("a != b : %d\n", a != b);
    return 0;
}
