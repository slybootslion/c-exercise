//
// Created by SlybootsLion on 2022/9/26.
//

#ifndef R05_E_LINKSTACK__LINKSTACK_H_
#define R05_E_LINKSTACK__LINKSTACK_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char data_t;

typedef struct node {
  data_t data;
  struct node *next;
} linknode_t;

typedef struct {
  linknode_t *top;
  int n;
} linkstack_t;

extern linkstack_t *create_empty_linkstack();
extern int is_empty_linkstack(linkstack_t *s);
extern int push_linkstack(linkstack_t *s, data_t data);
extern data_t pop_linkstack(linkstack_t *s);
extern data_t get_top_data(linkstack_t *s);

#endif //R05_E_LINKSTACK__LINKSTACK_H_
