//
// Created by SlybootsLion on 2022/8/29.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 10

typedef int datatype_t;

typedef struct {
    datatype_t buf[MAX];
    int n;
} seqlist_t;

// 1.为结构体在堆区分配空间，用l保存
seqlist_t *create_empty_seqlist() {
    seqlist_t *l = NULL;
    l = (seqlist_t *) malloc(sizeof(seqlist_t));
    if (NULL == l) {
        printf("malloc is fail\n");
        return NULL;
    }
    memset(l, 0, sizeof(seqlist_t));
    l->n = 0;
    return l;
}

// 2.判断顺序表是否满了
int is_full_seqlist(seqlist_t *l) {
    return l->n == MAX ? 1 : 0;
}

// 3.插入数据
void insert_data_seqlist(seqlist_t *l, datatype_t data) {
    l->buf[l->n] = data;
    l->n += 1;
}

// 4.输出数据
void printf_data_seqlist(seqlist_t *l) {
    for (int i = 0; i < l->n; ++i)
        printf("%d ", l->buf[i]);
    putchar('\n');
}

int main() {
    seqlist_t *l = NULL;
    l = create_empty_seqlist();
    datatype_t data;
    printf("please input %d number :", MAX);
    while (!is_full_seqlist(l)) {
        scanf("%d", &data);
        insert_data_seqlist(l, data);
    }
    printf_data_seqlist(l);

    free(l);
    l = NULL;
    return 0;
}

