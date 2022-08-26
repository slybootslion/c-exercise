//
// Created by SlybootsLion on 2022/8/25.
//

#ifndef BASIC_CALENDAR_H
#define BASIC_CALENDAR_H

#include <stdio.h>

#define LE_YEAR 1

int Isleap (int year);
int total_day(int year, int month, int day);
int max_day(int year, int month);
char *display_week(int year, int month, int day);
void display_month(int year, int month, int day);

#endif //BASIC_CALENDAR_H
