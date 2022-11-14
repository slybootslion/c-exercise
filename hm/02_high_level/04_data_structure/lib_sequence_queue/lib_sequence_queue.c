#include "../head.h"
#include "lib_sequence_queue.h"
#include "../lib_dynamic_array/lib_dynamic_array.h"

seq_queue init_sequence_queue() {
  d_array_t *array = init_dynamic_array(MAX);
  return array;
}

void push_sequence_queue(seq_queue queue, void *data) {
  if (queue == NULL || data == NULL)
    return;
  d_array_t *arr = queue;
  if (arr->size >= MAX)
    return;

  insert_dynamic_array(arr, data, arr->size);
}

void pop_sequence_queue(seq_queue queue) {
  d_array_t *arr = queue;
  if (queue == NULL || arr->size == 0)
    return;
  remove_by_pos(arr, 0);
}

void *front_sequence_queue(seq_queue queue) {
  d_array_t *arr = queue;
  if (queue == NULL || arr->size == 0)
    return NULL;
  return arr->address[0];
}

void *back_sequence_queue(seq_queue queue) {
  d_array_t *arr = queue;
  if (queue == NULL || arr->size == 0)
    return NULL;
  return arr->address[arr->size - 1];
}

int size_sequence_queue(seq_queue queue) {
  if (queue == NULL)
    return -1;
  d_array_t *arr = queue;
  return arr->size;
}

int is_empty_sequence_queue(seq_queue queue) {
  if (queue == NULL)
    return -1;
  d_array_t *arr = queue;
  return arr->size == 0;
}

void destroy_sequence_queue(seq_queue queue) {
  if (queue == NULL)
    return;
  destroy_dynamic_array(queue);
  queue = NULL;
}

