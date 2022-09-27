//
// Created by SlybootsLion on 2022/9/26.
//

#ifndef R03_E_LOOPLINK__LOOPLINK_H_
#define R03_E_LOOPLINK__LOOPLINK_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int datatype_t;

typedef struct node {
  datatype_t data;
  struct node *next;
} loopnode_t;

extern loopnode_t *create_empty_looplist();
extern void insert_head_looplist(loopnode_t *head, datatype_t data);
extern void printf_data_looplist(loopnode_t *head);
extern int is_empty_looplist(loopnode_t *head);

#endif //R03_E_LOOPLINK__LOOPLINK_H_
