#include "head.h"

int main() {
  linknode_t *head = create_empty_linklist();

  int n = 0;
  printf("please input you want insert data number:");
  scanf("%d", &n);

  datatype_t data;
  printf("please input %d data:", n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &data);
//    insert_head_linklist(head, data);
    insert_tail_linklist(head, data);
//    insert_order_linklist(head, data);
  }

  printf_data_linklist(head);
  return 0;
}
