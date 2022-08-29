//
// Created by SlybootsLion on 2022/8/29.
//

#ifndef BASIC_HEAD_H
#define BASIC_HEAD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} linknode_t;

extern linknode_t *create_empty_linklist();

extern void insert_order_linklist(linknode_t *head, int data);

extern void printf_data_linklist(linknode_t *head);

int is_empty_linklist(linknode_t *head);

int delete_data_linklist(linknode_t *head, int data);

#endif //BASIC_HEAD_H
