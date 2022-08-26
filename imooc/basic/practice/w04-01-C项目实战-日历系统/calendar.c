//
// Created by SlybootsLion on 2022/8/25.
//
#include "calendar.h"

int Isleap(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int max_day(int year, int month) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && Isleap(year))
        return days[month - 1] + 1;
    return days[month - 1];
}

int total_day(int year, int month, int day) {
    int count = 0;
    for (int i = 0; i < month - 1; ++i) {
        count += max_day(year, i + 1);
    }
    return count + day;
}

int check_week(int year, int month, int day) {
    if (month < 3)
        month += 12;
    int W = (day + 2 * month + 3 * (month + 1) / 5
             + year + year / 4 - year / 100 + year / 400 + 1) % 7;
    return W;
}

char *display_week(int year, int month, int day) {
    int W = check_week(year, month, day);
    char *weeks[] = {"星期日", "星期一", "星期二",
                     "星期三", "星期四", "星期五", "星期六"};
    return weeks[W];
}

void display_month(int year, int month, int day) {
    printf("\t\t%d年%d月\t\t\n", year, month);
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
    int W = check_week(year, month, 1);
    for (int i = 0; i < W; ++i) {
        putchar('\t');
    }
    for (int i = 0; i < max_day(year, month); ++i) {
        printf("%d\t", i + 1);
        if ((W + i + 1) % 7 == 0)
            putchar('\n');
    }
    putchar('\n');
}
