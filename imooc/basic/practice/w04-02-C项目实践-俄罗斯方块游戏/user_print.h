//
// Created by SlybootsLion on 2022/8/23.
//

#ifndef BASIC_USER_PRINT_H
#define BASIC_USER_PRINT_H

#include <stdio.h>

extern int next_num;
extern int next_mode;
extern int next_color;

extern int next_x;
extern int next_y;

extern int init_x;
extern int init_y;

extern int dynamic_x;
extern int dynamic_y;

extern int dynamic_num;
extern int dynamic_mode;
extern int dynamic_color;

extern int shape[7][4][18];

extern int matrix[24][28];

extern void print_mode_shape(int n, int m, int x, int y, int c);

extern void print_next_shape();

extern void erase_last_shape(int n, int m, int a, int b);

extern void store_current_shape();

extern void init_new_shape();

extern int judge_shape(int num, int mode, int x, int y);


#endif //BASIC_USER_PRINT_H
