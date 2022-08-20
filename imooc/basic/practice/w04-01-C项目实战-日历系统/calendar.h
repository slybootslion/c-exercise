//
// Created by SlybootsLion on 2022/8/20.
//

#ifndef BASIC_CALENDAR_H
#define BASIC_CALENDAR_H

#include <stdio.h>

#define LE_YEAR 1

extern int Isleap(int year);

extern int Total_day(int year, int month, int day);

extern int max_day(int year, int month);

extern int get_week(int year, int month, int day);

extern char *weekday(int year, int month, int day);

extern void display_month(int year, int month, int day);

#endif //BASIC_CALENDAR_H
