#include "../head.h"
#include "lib_link_queue.h"

typedef struct linkqueue {
  struct link_node p_head;
  int size;
  struct link_node *p_tail;
} link_queue_t;

link_queue init_link_queue() {
  link_queue_t *queue = malloc(sizeof(link_queue_t));
  if (queue == NULL)
    return NULL;
  queue->p_head.next = NULL;
  queue->p_tail = &queue->p_head;
  queue->size = 0;
  return queue;
}

void push_link_queue(link_queue queue, void *data) {
  if (queue == NULL || data == NULL)
    return;
  link_queue_t *link = queue;
  link_node_t *node = data;
  link->p_tail->next = node;
  node->next = NULL;
  link->p_tail = node;
  link->size++;
}

void pop_link_queue(link_queue queue) {
  link_queue_t *link = queue;
  if (queue == NULL || link->size == 0)
    return;
  if (link->size == 1) {
    link->p_head.next = NULL;
    link->p_tail = &link->p_head;
    link->size = 0;
    return;
  }
  link_node_t *node = link->p_head.next;
  link->p_head.next = node->next;
  link->size--;
}

void *front_link_queue(link_queue queue) {
  link_queue_t *link = queue;
  if (queue == NULL || link->size == 0)
    return NULL;
  return link->p_head.next;
}

void *back_link_queue(link_queue queue) {
  link_queue_t *link = queue;
  if (queue == NULL || link->size == 0)
    return NULL;
  return link->p_tail;
}

int size_link_queue(link_queue queue) {
  if (queue == NULL)
    return -1;
  link_queue_t *link = queue;
  return link->size;
}

int is_empty_link_queue(link_queue queue) {
  if (queue == NULL)
    return -1;
  link_queue_t *link = queue;
  return link->size == 0;
}

void destroy_link_queue(link_queue queue) {
  if (queue == NULL)
    return;
  free(queue);
  queue = NULL;
}
