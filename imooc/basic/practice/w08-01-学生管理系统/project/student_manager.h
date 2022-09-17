//
// Created by SlybootsLion on 2022/9/17.
//

#ifndef PROJECT__STUDENT_MANAGER_H_
#define PROJECT__STUDENT_MANAGER_H_

#include "linklist.h"
#include <stdarg.h>

enum option_id {
  ADD_STUDENT = 1, //添加学生
  FIND_STUDENT,   //寻找学生
  PRINT_STUDENT,  //输出学生
  MODIFY_STUDENT, //修改学生
  DELETE_STUDENT, //删除学生
  EXIT_SYSTEM     //退出系统
};

extern bool login_status;
extern void login_in();

extern void insert_student(linknode_t *head);
extern void find_student(linknode_t *head);
extern void display_student(linknode_t *head);
extern void update_student(linknode_t *head);
extern void delete_student(linknode_t *head);

extern void printlnf(const char *format, ...);
#endif //PROJECT__STUDENT_MANAGER_H_
