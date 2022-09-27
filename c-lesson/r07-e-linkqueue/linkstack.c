//
// Created by SlybootsLion on 2022/9/27.
//

#include "linkstack.h"

linkqueue_t *create_empty_linkqueue() {
  linknode_t *head = (linknode_t *) malloc(sizeof(linknode_t));
  head->next = NULL;

  linkqueue_t *q = (linkqueue_t *) malloc(sizeof(linkqueue_t));
  q->front = q->rear = head;

  return q;
}

int is_empty_linkqueue(linkqueue_t *q) {
  return q->front == q->rear;
}

void enter_linkqueue(linkqueue_t *q, data_t data) {
  linknode_t *temp = (linknode_t *) malloc(sizeof(linknode_t));
  temp->data = data;
  temp->next = q->rear->next;
  q->rear->next = temp;
  q->rear = temp;
}

data_t delete_linkqueue(linkqueue_t *q) {
  linknode_t *temp = q->front->next;
  data_t data = temp->data;

  q->front->next = temp->next;
  free(temp);
  temp = NULL;

  if (q->front->next == NULL)
    q->rear = q->front;

  return data;
}
