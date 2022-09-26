#include "looplink.h"

int main() {
  loopnode_t *head = create_empty_looplist();
  int n = 0, data;
  printf("input you want insert data number: ");
  scanf("%d", &n);

  printf("input %d data:", n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &data);
    insert_head_looplist(head, data);
  }
  printf_data_looplist(head);
  return 0;
}
