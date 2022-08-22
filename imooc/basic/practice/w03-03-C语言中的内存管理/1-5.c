//
// Created by SlybootsLion on 2022/8/22.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define N 5

int *get_memory_addr() {
    int *addr = NULL;
    addr = (int *) malloc(sizeof(int) * N);
    if (NULL == addr) {
        printf("malloc is fail!\n");
        return NULL;
    }
    memset(addr, 0, sizeof(sizeof(int) * N));
    return addr;
}

void input_array(int *p) {
    printf("please input %d data: ", N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &p[i]);
}

void output_array(int *p) {
    for (int i = 0; i < N; ++i)
        printf("%d ", p[i]);
    printf("\n");
}

int main() {

    int *r = NULL;
    r = get_memory_addr();
    input_array(r);
    output_array(r);
    return 0;
}
