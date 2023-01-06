#include <stdio.h>
#include "hashmap.h"

int main() {
  hashtable_t **h = create_hashtable();
  datatype_t value[] = {
	  {"hello", 123},
	  {"hello", 889},
	  {"world", 456},
	  {"asjfi", 789},
  };
  insert_data_hash(h, "hello", value[0]);
  insert_data_hash(h, "hello", value[1]);
  insert_data_hash(h, "world", value[2]);
  insert_data_hash(h, "asjfi", value[3]);
  int result[5] = {0};
  int ret = search_hash_table(h, "hello", result);
  printf("======\n");
  if (ret != 0) {
	for (int i = 0; i < ret; i++)
	  printf(" %d\n", result[i]);
  }
  printf_hash_table(h);
  return 0;
}
