#include "head.h"
#include "lib_dynamic_array/lib_dynamic_array.h"

void print_line() {
  printf("-------------\n");
}

void print_person(void *data) {
  person_t *p = data;
  printf("name: %s, age: %d\n", p->name, p->age);
}

int check_same_person(void *data, void *arr_data) {
  person_t *p1 = data;
  person_t *p2 = arr_data;
  return p1->age == p2->age && strcmp(p1->name, p2->name) == 0;
}

void test01() {
  d_array_t *arr = init_dynamic_array(5);
  person_t p1 = {"zhangsan1", 18};
  person_t p2 = {"zhangsan2", 18};
  person_t p3 = {"zhangsan3", 18};
  person_t p4 = {"zhangsan4", 18};
  person_t p5 = {"zhangsan5", 18};
  person_t p6 = {"zhangsan6", 28};

  printf("array capacity is: %d, array size is: %d\n\n", arr->capacity, arr->size);

  insert_dynamic_array(arr, &p1, 0);
  insert_dynamic_array(arr, &p2, 0);
  insert_dynamic_array(arr, &p3, 1);
  insert_dynamic_array(arr, &p4, -1);
  insert_dynamic_array(arr, &p5, 1);
  insert_dynamic_array(arr, &p6, 0);
  // 6 2 5 3 1 4
  print_array(arr, print_person);
  printf("array capacity is: %d, array size is: %d\n\n", arr->capacity, arr->size);

  remove_by_pos(arr, 2);
  print_array(arr, print_person);
  printf("array capacity is: %d, array size is: %d\n\n", arr->capacity, arr->size);

  person_t p_test = {"zhangsan2", 18};
  remove_by_value(arr, &p_test, check_same_person);
  print_array(arr, print_person);
  printf("array capacity is: %d, array size is: %d\n\n", arr->capacity, arr->size);

  destroy_dynamic_array(arr);
  arr = NULL;
}

void dynamic_array() {
  test01();
}
