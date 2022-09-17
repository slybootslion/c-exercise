//
// Created by SlybootsLion on 2022/9/17.
//
#include "linklist.h"

linknode_t *create_empty_linklist() {
  linknode_t *head = NULL;
  head = (linknode_t *) malloc(sizeof(linknode_t));
  if (head == NULL) {
    printf("malloc is failed!\n");
    return NULL;
  }
  memset(head, 0, sizeof(linknode_t));
  head->next = NULL;
  return head;
}

void insert_head_linklist(linknode_t *head, datatype_t data) {
  linknode_t *temp = NULL;
  temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;
  temp->next = head->next;
  head->next = temp;
}

void insert_tail_linklist(linknode_t *head, datatype_t data) {
  linknode_t *temp = NULL;
  temp = (linknode_t *) malloc(sizeof(linknode_t));
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
  while (p->next != NULL && data.score > p->next->data.score) {
    p = p->next;
  }
  temp->next = p->next;
  p->next = temp;
}

int is_empty_linklist(linknode_t *head) {
  return head->next == NULL;
}

int delete_data_linklist(linknode_t *head, int id) {
  linknode_t *p = NULL;
  linknode_t *q = NULL;

  int flag = 0;
  if (is_empty_linklist(head))
    return -1;
  p = head;

  while (p->next != NULL) {
    if (p->next->data.id == id) {
      q = p->next;
      p->next = q->next;
      free(q);
      q = NULL;
      flag = 1;
    } else {
      p = p->next;
    }
  }

  return flag == 0 ? -2 : 0;
}

void clean_up_linklist(linknode_t *head) {
  linknode_t *p = head;
  linknode_t *q = NULL;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}
