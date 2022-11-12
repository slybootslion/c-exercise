#include "head.h"
#include "./lib_linklist_basic/lib_linklist.h"

/*  */
void linklist() {
  person_t p1 = {"zhangsan1", 18};
  person_t p2 = {"zhangsan2", 18};
  person_t p3 = {"zhangsan3", 18};
  person_t p4 = {"zhangsan4", 18};
  person_t p5 = {"zhangsan5", 18};
  person_t p6 = {"zhangsan6", 28};

  link_list *list = init_linklist();

  insert_linklist(list, 0, &p1);
  insert_linklist(list, 0, &p2);
  insert_linklist(list, 1, &p3);
  insert_linklist(list, -1, &p4);
  insert_linklist(list, 1, &p5);
  insert_linklist(list, -1, &p6);

  foreach_linklist(list, print_person); // 2 5 3 1 4 6
  print_line();

  remove_linknode_by_pos(list, 4);
  foreach_linklist(list, print_person);
  print_line();

  person_t del_p = {"zhangsan2", 18};
  remove_linknode_by_value(list, &del_p, check_same_person);
  foreach_linklist(list, print_person);

}
