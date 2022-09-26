//
// Created by SlybootsLion on 2022/9/26.
//
#include "head.h"

linknode_t *create_empty_linklist() {
  linknode_t *head = NULL;
  head = (linknode_t *) malloc(sizeof(linknode_t));

  if (NULL == head) {
    printf("malloc is fail!\n");
    return NULL;
  }

  memset(head, 0, sizeof(linknode_t));
  head->next = NULL;

  return head;
}

void insert_head_linklist(linknode_t *head, datatype_t data) {
  linknode_t *temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;
  temp->next = head->next;
  head->next = temp;
}

void printf_data_linklist(linknode_t *head) {
  linknode_t *p = head;
  while (p->next != NULL) {
    printf("%d ", p->next->data);
    p = p->next;
  }
  putchar('\n');
}

void insert_tail_linklist(linknode_t *head, datatype_t data) {
  linknode_t *temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;
  linknode_t *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  temp->next = p->next;
  p->next = temp;
}

void insert_order_linklist(linknode_t *head, datatype_t data) {
  linknode_t *temp = NULL;
  temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;
  linknode_t *p = head;
  while (p->next != NULL && data > p->next->data) {
    p = p->next;
  }
  temp->next = p->next;
  p->next = temp;
}
