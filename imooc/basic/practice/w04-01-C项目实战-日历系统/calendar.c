//
// Created by SlybootsLion on 2022/8/20.
//
#include "calendar.h"

int Isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int max_day(int year, int month) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Isleap(year))
        months[1] = 29;
    return months[month];
}

int Total_day(int year, int month, int day) {
    int total = 0;
    for (int i = 0; i < month - 1; ++i)
        total += max_day(year, i);
    total += day;
    return total;
}

int get_week(int year, int month, int day) {
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}

char *weekday(int year, int month, int day) {
    int W = get_week(year, month, day);
    char *weeks[7] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    return weeks[W];
}

void display_month(int year, int month, int day) {
    printf("\t\t%d年%d月\n", year, month);
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");

    int first_W = get_week(year, month, 1);
    for (int i = 0; i < first_W; ++i)
        putchar('\t');

    int limit_day = max_day(year, month - 1);
    for (int i = 0; i < limit_day; ++i) {
        printf("%d\t", i + 1);
        if ((first_W + i + 1) % 7 == 0)
            putchar('\n');
    }
    putchar('\n');
}
