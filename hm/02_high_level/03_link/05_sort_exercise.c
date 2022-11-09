#include "head.h"

void sort_handler(void *arr, int ele_size, int len, int (*callback)(void *, void *)) {
  char *temp = malloc(ele_size);
  for (int i = 0; i < len; ++i) {
    int flag = i;
    for (int j = i + 1; j < len; ++j) {
      char *p_flag = (char *) arr + ele_size * flag; // 当前元素地址
      char *p_j = (char *) arr + ele_size * j; // j元素地址
      if (callback(p_j, p_flag))
        flag = j;
    }
    if (i != flag) {
      // 通过内存拷贝实现数据交换
      char *p_i = (char *) arr + ele_size * i;
      char *p_flag = (char *) arr + ele_size * flag;

      memcpy(temp, p_i, ele_size);
      memcpy(p_i, p_flag, ele_size);
      memcpy(p_flag, temp, ele_size);
    }
  }
  if (temp != NULL) {
    free(temp);
    temp = NULL;
  }
}

int int_arr_handler(void *num1, void *num2) {
  int *n1 = num1;
  int *n2 = num2;
  return *n1 < *n2;
}

void num_arr() {
  int arr[] = {10, 40, 30, 20, 50, 90, 70, 60, 80};
  int len = sizeof(arr) / sizeof(arr[0]);
  sort_handler(arr, sizeof(arr[0]), len, int_arr_handler);
  for (int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  putchar('\n');
}

typedef struct Person {
  char name[24];
  int age;
} person_t;

int struct_arr_handler(void *p1, void *p2) {
  person_t *person1 = p1;
  person_t *person2 = p2;
  return person1->age < person2->age;
}

void struct_arr() {
  person_t arr[] = {
      {"aaa", 50},
      {"bbb", 30},
      {"ccc", 10},
      {"ddd", 40},
      {"eee", 70},
  };
  int len = sizeof(arr) / sizeof(arr[0]);
  sort_handler(arr, sizeof(arr[0]), len, struct_arr_handler);

  for (int i = 0; i < len; ++i)
    printf("name: %s, age: %d\n", arr[i].name, arr[i].age);
}

void sort_exercise() {
  num_arr();
  struct_arr();
}
