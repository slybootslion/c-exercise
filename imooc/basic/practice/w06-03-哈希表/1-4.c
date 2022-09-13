//
// Created by SlybootsLion on 2022/9/8.
//
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define MAX 7

typedef int datatype_t;

typedef struct node {
    datatype_t data;
    struct node *next;
} hashtable_t;

hashtable_t **create_hashtable() {
    hashtable_t **h = NULL;
    h = (hashtable_t **) malloc(MAX * sizeof(hashtable_t *));
    memset(h, 0, sizeof(MAX * sizeof(hashtable_t *)));

    for (int i = 0; i < MAX; ++i)
        h[i] = NULL;

    return h;
}

void insert_data_hash(hashtable_t **h, datatype_t key) {
    hashtable_t *temp = NULL;
    hashtable_t **p = NULL;
    int index = key % MAX;
    for (p = &h[index]; *p != NULL; p = &((*p)->next)) {
        if ((*p)->data > key)
            break;
    }

    temp = (hashtable_t *) malloc(sizeof(hashtable_t));
    temp->data = key;

    temp->next = *p;
    *p = temp;
}

void printf_hash_table(hashtable_t **h) {
    hashtable_t **p = NULL;
    for (int i = 0; i < MAX; ++i) {
        printf("index = %d : ", i);
        for (p = &h[i]; *p != NULL; p = &((*p)->next))
            printf("%d ", (*p)->data);
        putchar('\n');
    }
}

int search_hash_table(hashtable_t **h, datatype_t key) {
    int index = key % MAX;
    hashtable_t **p = NULL;

    for (p = &h[index]; *p != NULL; p = &((*p)->next)) {
        if ((*p)->data == key)
            return 1;
    }

    return 0;
}

int main () {
    hashtable_t **h = NULL;
    datatype_t data[MAX] = {10, 22, 13, 11, 24, 7, 14};
    datatype_t value = 0;

    h = create_hashtable();

    for (int i = 0; i < MAX; ++i)
        insert_data_hash(h, data[i]);

    printf_hash_table(h);
    printf("please input you want to find value:");
    scanf("%d", &value);

    datatype_t ret = search_hash_table(h, value);
    if (ret == 0)
        printf("no such data in the hash tabled!\n");
    else
        printf("value = %d is exits\n", value);

    return 0;
}
