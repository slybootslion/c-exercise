#include "../head.h"
#include "lib_dynamic_array.h"

d_array_t *init_dynamic_array(int capacity) {
  if (capacity == 0) {
    return NULL;
  }
  d_array_t *arr_p = malloc(sizeof(d_array_t));
  if (arr_p == NULL)
    return NULL;
  arr_p->address = malloc(sizeof(void *) * capacity);
  arr_p->capacity = capacity;
  arr_p->size = 0;

  return arr_p;
}

void insert_dynamic_array(d_array_t *arr, void *data, int pos) {
  if (arr == NULL || data == NULL)
    return;
  // pos无效则尾部插入
  if (pos < 0 || pos > arr->size)
    pos = arr->size;

  // 如果数组满了，扩容
  if (arr->size == arr->capacity) {
    int capacity = arr->capacity * 2;
    void **space = malloc(sizeof(void *) * capacity);
    memcpy(space, arr->address, sizeof(void *) * arr->capacity);
    free(arr->address);
    arr->address = space;
    arr->capacity = capacity;
  }
  // 插入元素
  for (int i = arr->size; i >= pos; --i)
    arr->address[i + 1] = arr->address[i];
  arr->address[pos] = data;

  arr->size++;
}

void remove_by_pos(d_array_t *arr, int pos) {
  if (arr == NULL || pos < 0 || pos > arr->size - 1)
    return;

  for (int i = pos; i < arr->size; ++i)
    arr->address[i] = arr->address[i + 1];
  arr->size--;
}

void remove_by_value(d_array_t *arr, void *data, int (*callback)(void *, void *)) {
  if (arr == NULL || data == NULL)
    return;

  for (int i = 0; i < arr->size; ++i) {
    if (callback(data, arr->address[i])) {
      remove_by_pos(arr, i);
      break;
    }
  }
}

void destroy_dynamic_array(d_array_t *arr) {
  if (arr == NULL)
    return;

  if (arr->address != NULL){
    free(arr->address);
    arr->address = NULL;
  }
  free(arr);
  arr = NULL;
}

void print_array(d_array_t *arr, void (*print_callback)(void *)) {
  if (arr == NULL)
    return;

  for (int i = 0; i < arr->size; ++i)
    print_callback(arr->address[i]);
}
