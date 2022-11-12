#include "./head.h"
#include "./lib_linklist_company/lib_linklist_c.h"

typedef struct PersonC {
  node_c_t node;
  char name[64];
  int age;
} person_c_t;

void print_person_c(void *data) {
  person_c_t *person = data;
  printf("name: %s, age: %d\n", person->name, person->age);
}

void linklist_company() {
  person_c_t p1 = {NULL, "aaa", 18};
  person_c_t p2 = {NULL, "bbb", 18};
  person_c_t p3 = {NULL, "ccc", 18};
  person_c_t p4 = {NULL, "ddd", 18};
  person_c_t p5 = {NULL, "eee", 18};

  link_list_c *list = init_linklist_c();

  insert_linklist_c(list, 0, &p1);
  insert_linklist_c(list, 0, &p2);
  insert_linklist_c(list, 1, &p3);
  insert_linklist_c(list, -1, &p4);
  insert_linklist_c(list, 0, &p5);

  foreach_linklist_c(list, print_person_c);
  print_line();

  remove_linknode_by_pos_c(list, 1);
  foreach_linklist_c(list, print_person_c);

  destroy_linklist(list);
}
