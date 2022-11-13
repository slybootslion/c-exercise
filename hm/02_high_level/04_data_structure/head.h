//
// Created by SlybootsLion on 2022/11/10.
//

#ifndef INC_04_DATA_STRUCTURE__HEAD_H_
#define INC_04_DATA_STRUCTURE__HEAD_H_

typedef struct Person {
  char name[64];
  int age;
} person_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void dynamic_array();
extern void linklist();
extern void print_person(void *data);
extern int check_same_person(void *data, void *arr_data);
extern void print_line();
extern void linklist_company();
extern void sequence_stack ();
extern void link_stack_test ();

#endif //INC_04_DATA_STRUCTURE__HEAD_H_
