//
// Created by SlybootsLion on 2022/9/26.
//
#include "head.h"

seqlist_t *create_empty_seqlist() {
  seqlist_t *l = (seqlist_t *) malloc(sizeof(seqlist_t));
  if (NULL == l) {
    printf("malloc is fail!\n");
    return NULL;
  }

  memset(l, 0, sizeof(seqlist_t));
  l->n = 0;
  return l;
}

int is_full_seqlist(seqlist_t *l) {
  return l->n == MAX ? 1 : 0;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data) {
  l->buf[l->n] = data;
  l->n = l->n + 1;
}

void printf_data_seqlist(seqlist_t *l) {
  for (int i = 0; i < l->n; ++i) {
    printf("%d ", l->buf[i]);
  }
  printf("\n");
}

int is_empty_seqlist(seqlist_t *l) {
  return l->n == 0 ? 1 : 0;
}

int delete_data_seqlist(seqlist_t *l, datatype_t data) {
  if (is_empty_seqlist(l))
    return -1;

  int i = 0, j = 0;
  for (i = 0; i < l->n; ++i) {
    if (l->buf[i] != data) {
      l->buf[j] = l->buf[i];
      j++;
    }
  }
  l->n = j;
  if (i == j)
    return -2;
  else
    printf("delete %d is successful!\n", data);

  return 0;
}
