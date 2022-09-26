//
// Created by SlybootsLion on 2022/9/26.
//

#ifndef R01_E_LISTLINK__HEAD_H_
#define R01_E_LISTLINK__HEAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

#endif //R01_E_LISTLINK__HEAD_H_
