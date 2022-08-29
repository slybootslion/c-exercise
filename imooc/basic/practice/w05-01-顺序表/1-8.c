//
// Created by SlybootsLion on 2022/8/29.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX 2

struct student {
    char name[20];
    int id;
    int age;
};

typedef struct student datatype_t;

typedef struct {
    datatype_t buf[MAX];
    int n;
} seqlist_t;

seqlist_t *create_empty_seqlist();

int is_full_seqlist(seqlist_t *l);

void insert_data_seqlist(seqlist_t *l, datatype_t data);

void printf_data_seqlist(seqlist_t *l);

int main() {
    seqlist_t *l = create_empty_seqlist();
    printf("input student data [name id age]:\n");
    datatype_t data;
    while (!is_full_seqlist(l)) {
        scanf("%s%d%d", data.name, &data.id, &data.age);
        insert_data_seqlist(l, data);
    }
    printf_data_seqlist(l);
    free(l);
    l = NULL;
    return 0;
}

seqlist_t *create_empty_seqlist() {
    seqlist_t *l = (seqlist_t *) malloc(sizeof(seqlist_t));
    if (l == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    memset(l, 0, sizeof(seqlist_t));
    l->n = 0;
    return l;
}

int is_full_seqlist(seqlist_t *l) {
    return l->n == MAX ? 1 : 0;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data) {
    l->buf[l->n] = data;
    l->n += 1;
}

void printf_data_seqlist(seqlist_t *l) {
    printf("id\tname\tage\n");
    for (int i = 0; i < l->n; ++i)
        printf("%d\t%s\t%d\n", l->buf[i].id, l->buf[i].name, l->buf[i].age);
    putchar('\n');
}

