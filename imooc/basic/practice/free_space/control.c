
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shape[7][4][18] =
        {
                {
                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},                //
                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},                //
                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},                //[][]
                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2},                //[][]
                },
                {
                        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0},               //[]  [][][][]
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},               //[]
                        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0},               //[]
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},               //[]
                },
                {
                        {0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //  []    []      [][][]     []
                        {1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},               //[][][]  [][]      []     [][]
                        {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //        []                 []
                        {0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}                //
                },
                {
                        {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //[][]       []
                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},               //  [][]   [][]
                        {1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //         []
                        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},               //
                },
                {
                        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //  [][]   []
                        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1},               //[][]     [][]
                        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //           []
                        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1},               //
                },
                {
                        {0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //    []   []    [][][]  [][]
                        {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 1},               //[][][]   []    []        []
                        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //         [][]            []
                        {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1}                //
                },
                {
                        {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //[]       [][]  [][][]      []
                        {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 1},               //[][][]   []        []      []
                        {1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},               //         []              [][]
                        {0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 2, 1}},              //
        };

int n_x = 6;
int n_y = 6;
int n_num, n_mode, n_color;

int getch() {
    struct termios tm, tm_old;
    tcgetattr(0, &tm_old);
    cfmakeraw(&tm);
    tcsetattr(0, 0, &tm);
    int ch = getchar();
    tcsetattr(0, 0, &tm_old);

    return ch;
}

void print_mode_shape(int n, int m, int x, int y, int c) {
    int xx = x;
    int yy = y;
    for (int i = 0; i < 16; ++i) {
        if (i != 0 && i % 4 == 0) {
            yy += 1;
            xx = x;
        }
        if (shape[n][m][i] == 1)
            printf("\033[%d;%dH\033[%dm[]\033[0m", yy, xx, c);
        xx += 2;
    }
    fflush(NULL);
}

void init_shape() {
    srandom(time(NULL));
    n_num = random() % 7;
    n_mode = random() % 4;
    n_color = random() % 7 + 40;

    print_mode_shape(n_num, n_mode, n_x, n_y, n_color);

    fflush(NULL);
}

void eraser_shape(int n, int m, int a, int b) {
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


void change_shape() {
    int m = (n_mode + 1) % 4;
    eraser_shape(n_num, n_mode, n_x, n_y);
    n_mode = m;
    print_mode_shape(n_num, n_mode, n_x, n_y, n_color);
}

int move_left(int n, int m) {
    eraser_shape(n, m, n_x, n_y);
    n_x -= 2;
    print_mode_shape(n, m, n_x, n_y, n_color);
    return 0;
}

int move_right(int n, int m) {
    eraser_shape(n, m, n_x, n_y);
    n_x += 2;
    print_mode_shape(n, m, n_x, n_y, n_color);
    return 0;
}

int move_down(int n, int m) {
    eraser_shape(n, m, n_x, n_y);
    n_y++;
    print_mode_shape(n, m, n_x, n_y, n_color);
    return 0;
}

void key_control() {
    int ch;
    while (1) {
        ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        } else if (ch == '\r') {
            printf("down\n");
        } else if (ch == '\033') {
            ch = getch();
            if (ch == '[') {
                ch = getch();
                switch (ch) {
                    case 'A':
                        change_shape();
                        break;
                    case 'B':
                        move_down(n_num, n_mode);
                        break;
                    case 'C':
                        move_right(n_num, n_mode);
                        break;
                    case 'D':
                        move_left(n_num, n_mode);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

int main() {
    printf("\033[2J");
    printf("\033[?25l");
    init_shape();
    key_control();
    printf("\033[?25h");
    return 0;
}
