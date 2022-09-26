//
// Created by SlybootsLion on 2022/9/26.
//

#ifndef R02_E_REQLIST__HEAD_H_
#define R02_E_REQLIST__HEAD_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int datatype_t;

typedef struct {
  datatype_t buf[MAX];
  int n;
} seqlist_t;

extern seqlist_t *create_empty_seqlist();
extern int is_full_seqlist(seqlist_t *l);
extern void insert_data_seqlist(seqlist_t *l, datatype_t data);
extern void printf_data_seqlist(seqlist_t *l);
extern int is_empty_seqlist(seqlist_t *l);
extern int delete_data_seqlist(seqlist_t *l, datatype_t data);

#endif //R02_E_REQLIST__HEAD_H_
