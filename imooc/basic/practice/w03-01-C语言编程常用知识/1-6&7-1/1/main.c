#include <stdio.h>

extern int global;

extern void fun();

int main() {
    printf("global = %d\n", global);
    fun();
    return 0;
}
