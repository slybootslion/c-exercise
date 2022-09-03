//
// Created by SlybootsLion on 2022/9/3.
//

#ifndef BASIC_BITREE_H
#define BASIC_BITREE_H

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define N 6

typedef char data_t;
typedef struct bitree {
    int n;
    data_t data;
    struct bitree *lchild;
    struct bitree *rchild;
} bitree_t;

extern bitree_t *create_binatry_tree(int n);

#endif //BASIC_BITREE_H
