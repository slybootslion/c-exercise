//
// Created by SlybootsLion on 2022/9/28.
//

#ifndef R01_F_BITREE__BITREE_H_
#define R01_F_BITREE__BITREE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 6

typedef char data_t;

typedef struct bitree {
  int n; // 保存编号
  data_t data;
  struct bitree *lchild;
  struct bitree *rchild;
} bitree_t;

extern bitree_t *create_binary_tree(int n);
extern void pre_order(bitree_t *root);
extern void in_order(bitree_t *root);
extern void post_order(bitree_t *root);

#endif //R01_F_BITREE__BITREE_H_
