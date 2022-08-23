//
// Created by SlybootsLion on 2022/8/23.
//
#include "user_control.h"
#include "user_print.h"

int getch() {
    struct termios tm;
    tcgetattr(0, &tm_old);
    cfmakeraw(&tm);
    tcsetattr(0, 0, &tm);
    int ch = getchar();
    tcsetattr(0, 0, &tm_old);

    return ch;
}

void recover_attribute() {
    tcsetattr(0, 0, &tm_old);
}

void alarm_us(int n) {
    struct itimerval value = {
            {0, n},
            {0, n}
    };
    setitimer(ITIMER_REAL, &value, NULL);
}

void fall_down() {
    int ret;
    while (1) {
        ret = move_down(dynamic_num, dynamic_mode);
        if (ret == 1)
            break;
    }
}

int move_left(int n, int m) {
    if (dynamic_x <= 12)
        return 1;
    if (judge_shape(n, m, dynamic_x - 2, dynamic_y))
        return 1;
    erase_last_shape(n, m, dynamic_x, dynamic_y);
    dynamic_x -= 2;
    print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

int move_right(int n, int m) {
    if (dynamic_x + 2 * (4 - shape[n][m][16]) - 1 >= 39)
        return 1;
    if (judge_shape(n, m, dynamic_x + 2, dynamic_y))
        return 1;
    erase_last_shape(n, m, dynamic_x, dynamic_y);
    dynamic_x += 2;
    print_mode_shape(n, m, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

int change_shape() {
    int m = (dynamic_mode + 1) % 4;
    if (dynamic_x + 2 * (4 - shape[dynamic_num][m][16]) - 1 > 39)
        return 1;
    if (dynamic_y + (4 - shape[dynamic_num][m][17]) - 1 > 29)
        return 1;
    erase_last_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y);
    dynamic_mode = m;
    print_mode_shape(dynamic_num, dynamic_mode, dynamic_x, dynamic_y, dynamic_color);
    return 0;
}

void game_over() {
    printf("\033[32;9H*************  Game Over *************\033[0m");
    printf("\033[?25h");
    printf("\n\n");
}

void print_matrix() {
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 28; j += 2) {
            if (matrix[i][j] == 0)
                printf("\033[%d;%dH  \033[0m", i + 6, j + 12);
            else
                printf("\033[%d;%dH\33[%dm[]\033[0m", i + 6, j + 12, matrix[i][j]);
        }
    }
}

void print_score_level() {
    printf("\33[%d;%dH分数:%d\33[0m", score_y, score_x, user_score);
    printf("\33[%d;%dH等级:%d\33[0m", level_y, level_x, user_level);
    fflush(NULL);
}

void destroy_cond_line() {
    int flag = 0;
    for (int i = 0; i < 24; ++i) {
        flag = 1;
        for (int j = 0; j < 28; ++j) {
            if (matrix[i][j] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            user_score += 10;
            if (user_score % 100 == 0) {
                user_level++;
                tm /= 2;
                alarm_us(tm);
            }

            for (int k = i; k > 0; --k) {
                for (int j = 0; j < 28; ++j)
                    matrix[k][j] = matrix[k - 1][j];
            }
            print_matrix();
            print_score_level();
        }
    }
}

int move_down(int num, int mode) {
    if (dynamic_y + (4 - shape[num][mode][17]) - 1 >= 29 || judge_shape(num, mode, dynamic_x, dynamic_y + 1)) {
        store_current_shape();
        init_new_shape();
        destroy_cond_line();
        print_next_shape();
        return 1;
    }

    erase_last_shape(num, mode, dynamic_x, dynamic_y);
    dynamic_y++;
    print_mode_shape(num, mode, dynamic_x, dynamic_y, dynamic_color);

    return 0;
}

void key_control() {
    int ch;
    while (1) {
        ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;
        if (ch == '\r')
            change_shape();
        if (ch == '\033') {
            ch = getch();
            if (ch == '[') {
                ch = getch();
                switch (ch) {
                    case 'A':
                        fall_down();
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
