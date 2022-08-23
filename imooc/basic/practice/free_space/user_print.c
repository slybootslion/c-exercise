#include <stdlib.h>
#include <stdio.h>
#include "user_print.h"

void print_mode_shape(int n, int m, int x, int y, int c) {
    int xx = x;
    int yy = y;
    for (int i = 0; i < 16; ++i) {
        if (i != 0 && i % 4 == 0) {
            yy++;
            xx = x;
        }
        if (shape[n][m][i] == 1)
            printf("\033[%d;%dH\033[%dm[]\033[0m", yy, xx, c);
        xx += 2;
    }
    fflush(NULL);
}

void erase_last_shape(int n, int m, int a, int b) {
    int xx = a;
    int yy = b;
    for (int i = 0; i < 16; ++i) {
        if (i != 0 && i % 4 == 0) {
            yy++;
            xx = a;
        }
        if (shape[n][m][i] == 1)
            printf("\033[%d;%dH  \033[0m", yy, xx);
        xx += 2;
    }
    fflush(NULL);
}

void print_next_shape() {
    erase_last_shape(next_num, next_mode, next_x, next_y);

    next_num = (int) random() % 7;
    next_mode = (int) random() % 4;
    next_color = (int) random() % 7 + 40;

    print_mode_shape(next_num, next_mode, next_x, next_y, next_color);

    fflush(NULL);
}

void store_current_shape() {
    int m_line = dynamic_y - 6;
    int m_column = dynamic_x - 12;

    for (int i = 0; i < 16; ++i) {
        if (i != 0 && i % 4 == 0) {
            m_line++;
            m_column = dynamic_x - 12;
        }

        if (shape[dynamic_num][dynamic_mode][i] == 1) {
            matrix[m_line][m_column] = dynamic_color;
            matrix[m_line][m_column + 1] = dynamic_color;
        }
        m_column += 2;
    }
}

void init_new_shape() {
    dynamic_num = next_num;
    dynamic_mode = next_mode;
    dynamic_color = next_color;

    dynamic_x = init_x;
    dynamic_y = init_y;

    print_mode_shape(next_num, next_mode, dynamic_x, dynamic_y, dynamic_color);
}

int judge_shape(int num, int mode, int x, int y) {
    int m_line = y - 6;
    int m_column = x - 11;
    for (int i = 0; i < 16; ++i) {
        if (i != 0 && i % 4 == 0) {
            m_line++;
            m_column = x - 12;
        }
        if (shape[num][mode][i] == 1)
            if (matrix[m_line][m_column] != 0)
                return 1;
        m_column += 2;
    }
    return 0;
}

int move_down(int num, int mode) {
    if (dynamic_y + (4 - shape[num][mode][17]) - 1 >= 29 || judge_shape(num, mode, dynamic_x, dynamic_y + 1)) {
        store_current_shape();
        init_new_shape();
        print_next_shape();
        return 1;
    }

    erase_last_shape(num, mode, dynamic_x, dynamic_y);
    dynamic_y++;
    print_mode_shape(num, mode, dynamic_x, dynamic_y, dynamic_color);

    return 0;
}
