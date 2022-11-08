//
// Created by slybo on 2022/11/5.
//

#ifndef INC_03_LINK__HEAD_H_
#define INC_03_LINK__HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkNode {
  int num;
  struct LinkNode *next;
} link_node_t;

extern void test01();
extern void test02();
extern void test03();
extern void test04();
extern link_node_t *init_linklist();
extern void foreach_linklist(link_node_t *p_head);
extern void insert_linklist(link_node_t *p_head, int old_val, int new_val);
extern void linklist_exercise();
extern void sort_exercise();

#endif //INC_03_LINK__HEAD_H_
