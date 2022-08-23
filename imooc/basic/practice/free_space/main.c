#include <termios.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include "head.h"
#include "user_print.h"
#include "user_control.h"

extern int tm;

int score_x = 45;
int score_y = 18;
int level_x = 45;
int level_y = 22;

void print_start_ui() {
    printf("\033[2J");

    for (int i = 0; i < 47; ++i) {
        printf("\033[%d;%dH\033[43m \33[0m", 5, i + 10);
        printf("\033[%d;%dH\033[43m \33[0m", 30, i + 10);
    }

    for (int i = 0; i < 26; ++i) {
        printf("\033[%d;%dH\033[43m \033[0,", i + 5, 10);
        printf("\033[%d;%dH\033[43m \033[0,", i + 5, 40);
        printf("\033[%d;%dH\033[43m \033[0,", i + 5, 56);
    }

    for (int i = 0; i < 17; ++i)
        printf("\033[%d;%dH\33[43m \033[0m", 12, 40 + i);

    printf("\033[%d;%dH分数:\033[0m", score_y, score_x);
    printf("\033[%d;%dH等级:\033[0m", level_y, level_x);

    fflush(NULL);
}

void init_game_ui() {
    print_start_ui();
    getch();

    srand(time(NULL));
    dynamic_num = (int) random() % 7;
    dynamic_mode = (int) random() % 4;
    dynamic_color = (int) random() % 7 + 40;

    dynamic_x = init_x;
    dynamic_y = init_y;

    print_mode_shape(dynamic_num, dynamic_mode,
                     dynamic_x, dynamic_y, dynamic_color);

    print_next_shape();
    printf("\033[?25l");
}

int get_matrix_result(int n_line) {
    if (n_line < 0)
        return 1;
    for (int i = 0; i < 28; ++i) {
        if (matrix[n_line][i] != 0)
            return 1;
    }
    return 0;
}

int judge_end_game() {
    int n_line = 23;
    int n_count = 0;
    for (int i = 0; i < 24; ++i) {
        int no_zero = get_matrix_result(n_line);
        if (no_zero != 0)
            n_line--;
        else
            return 0;
    }
    return 1;
}

void sig_handler() {
    move_down(dynamic_num, dynamic_mode);
    if (judge_end_game() == 1) {
        game_over();
        exit(0);
    }
}

int main() {
    init_game_ui();
    signal(SIGALRM, sig_handler);
    alarm_us(tm);
    while (1);
    return 0;
}
