#include "head.h"

int main() {
  seqlist_t *l = create_empty_seqlist();
  datatype_t data;
  printf("please input %d number: ", MAX);
  while (!is_full_seqlist(l)) {
    scanf("%d", &data);
    insert_data_seqlist(l, data);
  }
  printf_data_seqlist(l);

  printf("========= =========\n");

  printf("input you want to delete data: ");
  scanf("%d", &data);

  int ret = delete_data_seqlist(l, data);
  if (ret < 0) {
    printf("seqlist is empty or data is not exist!\n");
    return -1;
  }

  printf_data_seqlist(l);

  free(l);
  l = NULL;
  return 0;
}
