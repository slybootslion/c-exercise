#ifndef INC_04_DATA_STRUCTURE__LIB_DYNAMIC_ARRAY_H_
#define INC_04_DATA_STRUCTURE__LIB_DYNAMIC_ARRAY_H_

typedef struct lib_dynamic_array {
  void **address;
  int capacity;
  int size;
} d_array_t;

d_array_t *init_dynamic_array(int capacity);

void insert_dynamic_array(d_array_t *arr, void *data, int pos);

void remove_by_pos(d_array_t *arr, int pos);

void remove_by_value(d_array_t *arr, void *data, int (*callback)(void *, void *));

void destroy_dynamic_array(d_array_t *arr);

void print_array(d_array_t *arr, void (*print_callback)(void *));

#endif //INC_04_DATA_STRUCTURE__LIB_DYNAMIC_ARRAY_H_
