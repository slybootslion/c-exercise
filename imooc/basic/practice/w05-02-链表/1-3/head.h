//
// Created by SlybootsLion on 2022/8/29.
//

#ifndef BASIC_HEAD_H
#define BASIC_HEAD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype_t;

typedef struct node {
    datatype_t data;
    struct node *next;
} linknode_t;

extern linknode_t *create_empty_linklist();

extern void insert_head_linklist(linknode_t *head, datatype_t data);

extern void printf_data_linklist(linknode_t *head);

extern void insert_tail_linklist(linknode_t *head, datatype_t data);

extern void insert_order_linklist(linknode_t *head, datatype_t data);

extern int is_empty_linklist(linknode_t *head);

void reverse_data_linklist(linknode_t *head);

void clean_up_linklist(linknode_t *head);

#endif //BASIC_HEAD_H
