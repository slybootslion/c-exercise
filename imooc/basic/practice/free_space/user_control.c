#include <termios.h>
#include <stdio.h>
#include <sys/time.h>
#include "user_control.h"
#include "user_print.h"

//
// Created by SlybootsLion on 2022/8/23.
//
int getch() {
    struct termios tm, tm_old;
    tcgetattr(0, &tm_old);
    cfmakeraw(&tm);
    tcsetattr(0, 0, &tm);
    int ch = getchar();
    tcsetattr(0, 0, &tm_old);

    return ch;
}

void alarm_us(int n) {
    struct itimerval value = {
            {0, n},
            {0, n}
    };

    setitimer(ITIMER_REAL, &value, NULL);
}

void game_over() {
    printf("\033[32;9H*************  Game Over *************\033[0m");
    printf("\033[?25h");
    printf("\n\n");
}

void key_control() {
    int ch;
    while (1) {
        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;
        if (ch == '\r')
            fall_down();
        if (ch == '\033') {
            ch = getch();
            if (ch == '[') {
                ch = getch();
                switch (ch) {
                    case 'A':
                        change_shape();
                        break;
                    case 'B':
                        move_down(dynamic_num, dynamic_mode);
                        break;
                    case 'C':
                        move_right(dynamic_num, dynamic_mode);
                        break;
                    case 'D':
                        move_left(dynamic_num, dynamic_mode);
                        break;
                    default:
                        break;

                }
            }
        }
    }
    game_over();
}

// ----------------------------
int change_shape() {

}
