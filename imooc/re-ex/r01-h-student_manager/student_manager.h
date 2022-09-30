//
// Created by SlybootsLion on 2022/9/30.
//

#ifndef R01_H_STUDENT_MANAGER__STUDENT_MANAGER_H_
#define R01_H_STUDENT_MANAGER__STUDENT_MANAGER_H_

#include "linklist.h"

enum option_id {
  ADD_STUDENT = 1,
  FIND_STUDENT,
  PRINT_STUDENT,
  MODIFY_STUDENT,
  DELETE_STUDENT,
  EXIT_SYSTEM,
};

extern bool login_status;
extern void login_in();

extern void insert_student(linknode_t *head);
extern void find_student(linknode_t *head);
extern void display_student(linknode_t *head);
extern void update_student(linknode_t *head);
extern void delete_student(linknode_t *head);
extern void display_update_info();
extern void user_change_data(linknode_t *temp, int id);
extern void update_student_info(linknode_t *temp);

#endif //R01_H_STUDENT_MANAGER__STUDENT_MANAGER_H_
