#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define NULL_KEY -1

typedef int datatype_t;
typedef struct node {
  datatype_t *elem_p;
  int n;
} hashtable_t;

hashtable_t *create_hashtable() {
  hashtable_t *t = (hashtable_t *) malloc(sizeof(hashtable_t));

  t->elem_p = (datatype_t *) malloc(MAX * sizeof(datatype_t));
  t->n = 0;

  for (int i = 0; i < MAX; ++i)
    t->elem_p[i] = NULL_KEY;

  return t;
}

int is_full_hashtable(hashtable_t *h) {
  return h->n == MAX;
}

void insert_data_hash(hashtable_t *h, datatype_t key) {
  int index = key % MAX;
  if (is_full_hashtable(h)) {
    printf("hash table is full!\n");
    return;
  }
  while (h->elem_p[index] != NULL_KEY) {
    index = (index + 1) % MAX;
  }
  h->elem_p[index] = key;
  h->n++;
}

void printf_hash_table(hashtable_t *h) {
  for (int i = 0; i < MAX; ++i) {
    printf("%d ", h->elem_p[i]);
  }
  printf("\n");
}

int search_hash_table(hashtable_t *h, datatype_t key) {
  int index = key % MAX;
  while (h->elem_p[index] != key) {
    index = (index + 1) % MAX;
    if (h->elem_p[index] == NULL_KEY || index == key % MAX)
      return -1;
  }
  return index;
}

int main() {
  hashtable_t *h = create_hashtable();
  datatype_t data[MAX] = {13, 39, 27, 28, 26, 30, 38, 16, 14, 19};

  for (int i = 0; i < MAX; ++i)
    insert_data_hash(h, data[i]);

  printf_hash_table(h);

  datatype_t value;
  printf("please input you want find value:");
  scanf("%d", &value);

  int ret = search_hash_table(h, value);
  if (ret < 0) {
    printf("no such data in the hash table!\n");
  } else {
    printf("hashtable index is %d\n", ret);
  }

  insert_data_hash(h, 800);
  free(h->elem_p);
  free(h);
  h = NULL;

  return 0;
}
