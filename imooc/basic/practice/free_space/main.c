#include "head.h"

int main() {
    printf("\033[2J");
    int x = 6;
    int y = 6;
    for (int k = 0; k < 7; ++k) {
        for (int i = 0; i < 4; ++i) {
            print_mode_shape(k, i, x, y, 43);
            x = x + 12;
        }
        x = 6;
        y = y + 4;
        printf("\n");
        getchar();
    }
    printf("\033[?25h");
    return 0;
}
