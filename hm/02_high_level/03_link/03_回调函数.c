#include "head.h"

// 提供一个函数，可以打印任意类型的数据
void my_print(void *data, void(*mp)(void *)) {
  mp(data);
}

typedef struct Person {
  char name[64];
  int age;
} person_t;

void print_int(void *data) {
  int *num = data;
  printf("%d\n", *num);
}

void print_double(void *data) {
  double *num = data;
  printf("%f\n", *num);
}

void print_person(void *data) {
  person_t *person = data;
  printf("name: %s, age: %d\n", person->name, person->age);
}

void callback01() {
  int a = 10;
  my_print(&a, print_int);

  double b = 3.14;
  my_print(&b, print_double);

  person_t p1 = {"zhangsan", 18};
  my_print(&p1, print_person);
}

// 1、传入数组首地址 2、每个元素大小 3、数组长度 4、回调函数
void print_all_array(void *arr, int ele_size, int len, void(*fun)(void *)) {
  char *p = arr;
  for (int i = 0; i < len; ++i) {
    // 获取每个元数首地址
    char *p_address = p + ele_size * i;
    fun(p_address);
  }
}

person_t person_array[] = {
    {"zhangsan", 18},
    {"lisi", 19},
    {"wangwu", 20}
};

void callback02() {
  int arr_int[] = {1, 2, 3, 4, 5};
  double arr_double[] = {1.1, 1.2, 1.3, 1.4, 1.5};
  print_all_array(arr_int, sizeof(int), 5, print_int);
  print_all_array(arr_double, sizeof(double), 5, print_double);
  print_all_array(person_array, sizeof(person_t), 3, print_person);
}

int find_array_element(void *array, int ele_size, int len, void *data, int(my_compare)(void *, void *)) {
  char *p = array;
  for (int i = 0; i < len; ++i) {
    char *p_address = p + ele_size * i;
    if (my_compare(data, p_address)) {
      return 1;
    }
  }
  return 0;
}

int compare_person(void *p, void *p_address) {
  person_t *p1 = p, *p2 = p_address;
  return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void callback03() {
  person_t p = {"wangwu", 20};
  int res = find_array_element(person_array, sizeof(person_t), 3, &p, compare_person);
  res == 1 ? printf("had element\n") : printf("no have element\n");
}

void test04() {
//  callback01();
//  callback02();
  callback03();
}
