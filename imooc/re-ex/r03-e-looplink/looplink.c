//
// Created by SlybootsLion on 2022/9/26.
//
#include "looplink.h"

loopnode_t *create_empty_looplist() {
  loopnode_t *head = (loopnode_t *) malloc(sizeof(loopnode_t));
  if (NULL == head) {
    printf("malloc is fail!\n");
    return NULL;
  }
  memset(head, 0, sizeof(loopnode_t));
  head->next = head;
  return head;
}

void insert_head_looplist(loopnode_t *head, datatype_t data) {
  loopnode_t *temp = (loopnode_t *) malloc(sizeof(loopnode_t));
  temp->data = data;
  temp->next = head->next;
  head->next = temp;
}

void printf_data_looplist(loopnode_t *head) {
  loopnode_t *p = head;
  while (p->next != head) {
    printf("%d ", p->next->data);
    p = p->next;
  }
  printf("\n");
}

int is_empty_looplist(loopnode_t *head) {
  return head->next == head ? 1 : 0;
}

