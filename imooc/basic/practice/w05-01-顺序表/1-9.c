//
// Created by SlybootsLion on 2022/8/29.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX 10

typedef int datatype_t;

typedef struct {
    datatype_t buf[MAX];
    int n;
} seqlist_t;

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

void insert_data_seqlist(seqlist_t *l, datatype_t data) {
    l->buf[l->n] = data;
    l->n += 1;
}

void printf_data_seqlist(seqlist_t *l) {
    for (int i = 0; i < l->n; ++i)
        printf("%d ", l->buf[i]);
    putchar('\n');
}

int is_empty_seqlist(seqlist_t *l) {
    return l->n == 0 ? 1 : 0;
}

int delete_data_seqlist(seqlist_t *l, datatype_t data) {
    if (is_empty_seqlist(l))
        return -1;
    int i = 0, j = 0;
    for (i = 0; i < l->n; ++i) {
        if (l->buf[i] != data) {
            l->buf[j] = l->buf[i];
            j++;
        }
    }
    l->n = j;
    if (i == j)
        return -2;
    else
        printf("delete %d is successful!\n", data);
    return 0;
}

int main() {
    seqlist_t *l = NULL;
    datatype_t data;

    int n, ret = 0, post;
    l = create_empty_seqlist();
    for (int i = 0; i < MAX; ++i)
        insert_data_seqlist(l, i);
    printf_data_seqlist(l);

    printf("===========\n");
    printf("input you want to delete data: \n");
    scanf("%d", &data);

    ret = delete_data_seqlist(l, data);
    if (ret < 0) {
        printf("seqlist is empty or data is not exist!\n");
        return -1;
    }

    printf_data_seqlist(l);

    free(l);
    l = NULL;

    return 0;
}
