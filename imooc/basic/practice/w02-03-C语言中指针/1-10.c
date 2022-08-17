#include <stdio.h>

/*
 int a[5] = {1,3,5,7,9};
int *p = NULL;
int **q = NULL;

//1.要求搭建通过p输出数组中所有的内容
//2.要求搭建通过q输出数组中所有的内容
 * */

int main() {

    int a[5] = {1, 3, 5, 7, 9};
    int *p = NULL;
    int **q = NULL;

    p = a;
    q = &p;
    int len = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < len; ++i) {
        printf("p[%d] = %d\t", i, p[i]);
        printf("*(p + %d) = %d\t", i, *(p + i));
        printf("(*q)[%d] = %d\t", i, (*q)[i]);
        printf("*(*q + %d) = %d\n", i, *(*q + i));
    }

    return 0;
}
