//
// Created by SlybootsLion on 2022/8/30.
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
} loopnode_t;

extern loopnode_t *create_empty_looplist();

extern void insert_head_looplist(loopnode_t *head, datatype_t data);

extern void printf_data_looplist(loopnode_t *head);

extern int is_empty_looplist(loopnode_t *head);

#endif //BASIC_HEAD_H
