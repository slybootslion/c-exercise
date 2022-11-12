#include "lib_sequence_stack.h"

typedef struct sequence_stack {
  void *data[MAX];
  int size;
} s_stack;


seq_stack init_sequence_stack() {
  s_stack *stack = malloc(sizeof(s_stack));
  if (stack == NULL) return NULL;
  memset(stack->data, 0, sizeof(void *) * MAX);
  stack->size = 0;
  return stack;
}

void push_sequence_stack(seq_stack s, void *data) {
  if (s == NULL || data == NULL) return;
  s_stack *stack = s;
  if (stack->size >= MAX) return;
  stack->data[stack->size] = data;
  stack->size++;
}

void pop_sequence_stack(seq_stack s) {
  if (s == NULL) return;
  s_stack *stack = s;
  if (stack->size == 0) return;
  stack->data[stack->size - 1] = NULL;
  stack->size--;
}

void *top_sequence_stack(seq_stack s) {
  if (s == NULL) return NULL;
  s_stack *stack = s;
  if (stack->size == 0) return NULL;
  return stack->data[stack->size - 1];
}

int size_sequence_stack(seq_stack s) {
  if (s == NULL) return -1;
  s_stack *stack = s;
  return stack->size;
}

int is_empty_sequence_stack(seq_stack s) {
  if (s == NULL) return -1;
  s_stack *stack = s;
  return stack->size == 0;
}

void destroy_sequence_stack(seq_stack s) {
  if (s == NULL) return;
  free(s);
  s = NULL;
}
