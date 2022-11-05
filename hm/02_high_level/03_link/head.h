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
}link_node_t;

extern void test01 ();
extern void test02 ();

#endif //INC_03_LINK__HEAD_H_
