//
// Created by SlybootsLion on 2022/9/26.
//
#include "seqstack.h"

seqstack_t *create_empty_seqstack() {
  seqstack_t *s = (seqstack_t *) malloc(sizeof(seqstack_t));
  if (NULL == s) {
    printf("mallco is fail\n");
    return NULL;
  }
  memset(s, 0, sizeof(seqstack_t));
  s->top = -1;
  return s;
}

int is_empty_seqstack(seqstack_t *s) {
  return s->top == -1 ? 1 : 0;
}

int is_full_seqstack(seqstack_t *s) {
  return s->top == MAX - 1 ? 1 : 0;
}

void push_seqstack(seqstack_t *s, data_t data) {
  s->buf[++s->top] = data;
}

data_t pop_seqstack(seqstack_t *s) {
  return s->buf[s->top--];
}

data_t get_top_data(seqstack_t *s) {
  return s->buf[s->top];
}

