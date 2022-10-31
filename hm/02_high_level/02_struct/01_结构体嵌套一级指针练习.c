#include "head.h"

typedef struct Person {
  char *name;
  int age;
} Person;

#define count 3

Person **allocate_space_1() {
  Person **temp = malloc(sizeof(Person) * count);

  for (int i = 0; i < count; ++i) {
    temp[i] = malloc(sizeof(Person));
    temp[i]->name = malloc(sizeof(char) * 64);
    sprintf(temp[i]->name, "name_%d", i + 1);
    temp[i]->age = i + 20;
  }

  return temp;
}

void print_person(Person **p, int len) {
  for (int i = 0; i < len; ++i)
    printf("姓名： %s, 年龄：%d\n", p[i]->name, p[i]->age);
}

void free_space_1(Person **p, int len) {
  for (int i = 0; i < len; ++i) {
    if (p[i]->name != NULL) {
      printf("%s被释放了\n", p[i]->name);
      free(p[i]->name);
      p[i]->name = NULL;
    }
    if (p[i] != NULL) {
      free(p[i]);
      p[i] = NULL;
    }
  }
  free(p);
}

void exec01() {
  Person **p_array = allocate_space_1();
  print_person(p_array, count);
  free_space_1(p_array, count);
  p_array = NULL;
}
