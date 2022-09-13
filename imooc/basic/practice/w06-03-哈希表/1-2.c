//
// Created by SlybootsLion on 2022/9/8.
//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX 10
#define NULL_KEY -1

typedef int datatype_t;

typedef struct node {
    datatype_t *elem_p;
    int n;
} hashtable_t;

hashtable_t *create_hashtable() {
    hashtable_t *h = NULL;
    h = (hashtable_t *) malloc(sizeof(hashtable_t));
    h->elem_p = (datatype_t *) malloc(MAX * sizeof(datatype_t));
    h->n = 0;

    for (int i = 0; i < MAX; ++i)
        h->elem_p[i] = NULL_KEY;

    return h;
}

int is_full_hashtable(hashtable_t *h) {
    return h->n == MAX;
}

void insert_data_hash(hashtable_t *h, datatype_t key) {
    if (is_full_hashtable(h)) {
        printf("hash table is full!\n");
        return;
    }

    int index = key % MAX;

    while (h->elem_p[index] != NULL_KEY)
        index = (index + 1) % MAX;

    h->elem_p[index] = key;
    h->n++;
}

void printf_hash_table(hashtable_t *h) {
    for (int i = 0; i < MAX; ++i)
        printf("%d ", h->elem_p[i]);
    putchar('\n');
}

int search_hash_table(hashtable_t *h, datatype_t key) {
    int index = key % MAX;

    while (h->elem_p[index] != key) {
        index = (index + 1) % MAX;
        if ((h->elem_p[index] == NULL_KEY) || index == key % MAX)
            return -1;
    }

    return index;
}

int main() {
    hashtable_t *h = NULL;

    datatype_t data[MAX] = {13, 29, 27, 28, 26, 30, 38, 16, 14, 19};
    datatype_t value = 0;
    h = create_hashtable();

    for (int i = 0; i < MAX; ++i)
        insert_data_hash(h, data[i]);

    printf_hash_table(h);
    printf("please input you want to find value:");
    scanf("%d", &value);
    datatype_t ret = search_hash_table(h, value);
    if (ret < 0)
        printf("no such data in the hash_tabled!\n");
    else
        printf("hashtable index is %d\n", ret);
    insert_data_hash(h, 800);
    free(h->elem_p);
    free(h);
    h = NULL;

    return 0;
}
