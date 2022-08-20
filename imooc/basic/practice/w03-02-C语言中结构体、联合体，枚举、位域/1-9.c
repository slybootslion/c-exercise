#include <stdio.h>

//
// Created by SlybootsLion on 2022/8/20.
//
enum DAY {
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
};

int main() {

    enum DAY today = THU;

    today = 8;
    printf("today: %d\n", today);

    int date = 8;
    printf("please input you wanti check date: ");
    scanf("%d", &date);

    switch (date) {
        case MON:
            printf("today is MON\n");
            break;
        case TUE:
            printf("today is TUE\n");
            break;
        case WED:
            printf("today is WED\n");
            break;
        case THU:
            printf("today is THU\n");
            break;
        case FRI:
            printf("today is FRI\n");
            break;
        case SAT:
            printf("today is SAT\n");
            break;
        case SUN:
            printf("today is SUN\n");
            break;
    }

    return 0;
}
