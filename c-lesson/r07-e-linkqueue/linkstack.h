//
// Created by SlybootsLion on 2022/9/27.
//

#ifndef R07_E_LINKQUEUE__LINKSTACK_H_
#define R07_E_LINKQUEUE__LINKSTACK_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int data_t;

typedef struct node {
  data_t data;
  struct node *next;
} linknode_t;

typedef struct {
  linknode_t *front;
  linknode_t *rear;
} linkqueue_t;

extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t *q);
extern int enter_linkqueue(linkqueue_t *q, data_t data);
extern data_t delete_linkqueue(linkqueue_t *q);

#endif //R07_E_LINKQUEUE__LINKSTACK_H_
