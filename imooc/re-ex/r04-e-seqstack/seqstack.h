//
// Created by SlybootsLion on 2022/9/26.
//

#ifndef R04_E_SEQSTACK__SEQSTACK_H_
#define R04_E_SEQSTACK__SEQSTACK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

typedef int data_t;

typedef struct {
  data_t buf[MAX];
  int top;
} seqstack_t;

extern seqstack_t *create_empty_seqstack();
extern int is_empty_seqstack(seqstack_t *s);
extern int is_full_seqstack(seqstack_t *s);
extern void push_seqstack(seqstack_t *s, data_t data);
extern data_t pop_seqstack(seqstack_t *s);
extern data_t get_top_data(seqstack_t *s);

#endif //R04_E_SEQSTACK__SEQSTACK_H_
