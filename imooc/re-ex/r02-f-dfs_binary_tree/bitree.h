//
// Created by SlybootsLion on 2022/9/28.
//

#ifndef R02_F_DFS_BINARY_TREE__BITREE_H_
#define R02_F_DFS_BINARY_TREE__BITREE_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef char data_t;

typedef struct bitree {
  int n;
  data_t data;
  struct bitree *lchild;
  struct bitree *rchild;
} bitree_t;

extern bitree_t *create_binary_tree(int n);
extern void pre_order(bitree_t *root);
extern void in_order(bitree_t *root);
extern void post_order(bitree_t *root);

#endif //R02_F_DFS_BINARY_TREE__BITREE_H_
