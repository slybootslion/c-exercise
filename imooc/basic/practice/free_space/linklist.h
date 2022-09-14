//
// Created by ubuntu on 22-8-31.
//

#ifndef EMBEDDED_LINKLIST_H
#define EMBEDDED_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype_t;

typedef struct node {
    datatype_t data; // 数据域：保存有效数据
    struct node *next; // 指针域：保存下一个结点的地址
} linklist_t;

extern linklist_t *create_empty_linklist();

extern void insert_tail_linklist(linklist_t *head, datatype_t data);

extern void print_data_linklist(linklist_t *head);

extern void sort_linklist(linklist_t *head);

#endif //EMBEDDED_LINKLIST_H
