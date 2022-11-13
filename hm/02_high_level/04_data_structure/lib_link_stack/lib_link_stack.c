#include "../head.h"
#include "lib_link_stack.h"

typedef struct link_node {
  struct link_node *next;
} link_node_t;

typedef struct linkstack {
  link_node_t p_head;
  int size;
} linkstack_t;

link_stack init_link_stack() {
  linkstack_t *stack = malloc(sizeof(linkstack_t));
  if (stack == NULL)
    return NULL;

  stack->p_head.next = NULL;
  stack->size;
  return stack;
}

void push_link_stack(link_stack s, void *data) {
  if (s == NULL || data == NULL)
    return;
  linkstack_t *stack = s;
  link_node_t *node = data;
  node->next = stack->p_head.next;
  stack->p_head.next = node;
  stack->size++;
}

void pop_link_stack(link_stack s) {
  linkstack_t *stack = s;
  if (s == NULL || stack->size == 0)
    return;
  link_node_t *first = stack->p_head.next;
  stack->p_head.next = first->next;
  stack->size--;
}

void *top_link_stack(link_stack s) {
  linkstack_t *stack = s;
  if (s == NULL || stack->size == 0)
    return NULL;
  return stack->p_head.next;
}

int size_link_stack(link_stack s) {
  linkstack_t *stack = s;
  if (s == NULL)
    return -1;
  return stack->size;
}

int is_empty_link_stack(link_stack s) {
  linkstack_t *stack = s;
  if (s == NULL)
    return -1;
  return stack->size == 0;
}

void destroy_link_stack(link_stack s) {
  if (s == NULL)
    return;
  free(s);
  s = NULL;
}
