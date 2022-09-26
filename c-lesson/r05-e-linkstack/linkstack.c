//
// Created by SlybootsLion on 2022/9/26.
//
#include "linkstack.h"

linkstack_t *create_empty_linkstack() {
  linkstack_t *s = (linkstack_t *) malloc(sizeof(linkstack_t));
  s->top = NULL;
  s->n = 0;
  return s;
}

int is_empty_linkstack(linkstack_t *s) {
  return s->top == NULL;
}

int push_linkstack(linkstack_t *s, data_t data) {
  linknode_t *temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;

  temp->next = s->top;
  s->top = temp;
  s->n++;

  return 0;
}

data_t pop_linkstack(linkstack_t *s) {
  linknode_t *temp = s->top;
  // 去除删除节点数据
  data_t data = temp->data;
  //  更新top指针，用删除节点的指针域更新
  s->top = temp->next;

  free(temp);
  temp = NULL;

  s->n--;

  return data;
}

data_t get_top_data(linkstack_t *s) {
  return s->top->data;
}
