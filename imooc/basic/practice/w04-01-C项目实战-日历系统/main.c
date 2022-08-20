//
// Created by SlybootsLion on 2022/8/20.
//

#include <string.h>
#include "calendar.h"

int main() {
    int year, month, day;

    printf("please input [year month day]: \n");
    scanf("%d%d%d", &year, &month, &day);

    putchar('\n');
    printf("====================================\n");

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Input date is error!\n");
        return -1;
    }

    int ret = Isleap(year);
    ret == LE_YEAR ?
    printf("%d年%d月%d日是闰年\n", year, month, day) :
    printf("%d年%d月%d日不是闰年\n", year, month, day);

    ret = Total_day(year, month, day);
    printf("%d年%d月%d号是这一年的第%d天。\n", year, month, day, ret);

    static char s[3];
    strcpy(s, weekday(year, month, day));
    printf("%d年%d月%d日是%s\n", year, month, day, s);

    display_month(year, month, day);

    return 0;
}
