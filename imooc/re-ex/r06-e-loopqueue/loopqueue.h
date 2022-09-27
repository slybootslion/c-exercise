//
// Created by SlybootsLion on 2022/9/27.
//

#ifndef R06_E_LOOPQUEUE__LOOPQUEUE_H_
#define R06_E_LOOPQUEUE__LOOPQUEUE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int data_t;

#define N 5

typedef struct {
  data_t buf[N];
  int front;
  int rear;
} loopqueue_t;

extern loopqueue_t *create_empty_loopqueue();
extern int is_empty_loopqueue(loopqueue_t *q);
extern int is_full_loopqueue(loopqueue_t *q);
extern void enter_loopqueue(loopqueue_t *q, data_t data);
extern data_t delete_loopqueue(loopqueue_t *q);

#endif //R06_E_LOOPQUEUE__LOOPQUEUE_H_
