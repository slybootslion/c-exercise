//
// Created by SlybootsLion on 2022/9/3.
//

#ifndef BASIC_LINKSTACK_H
#define BASIC_LINKSTACK_H

#include "bitree.h"

typedef bitree_t *datatype_t;

typedef struct node {
    datatype_t data;
    struct node *next;
} linknode_t;

typedef struct {
    linknode_t *top;
    int n;
} linkstack_t;

extern linkstack_t *create_empty_linkstack();

extern int is_empty_linkstack(linkstack_t *s);

extern void push_linkstack(linkstack_t *s, datatype_t data);

extern datatype_t pop_linkstack(linkstack_t *s);

extern datatype_t get_top_data(linkstack_t *s);

#endif //BASIC_LINKSTACK_H
