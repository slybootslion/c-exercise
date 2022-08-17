#include <stdio.h>

int main() {
    char a[] = {"zhao"};
    char b[] = {"qian"};
    char c[] = {"sun"};

    char *q[] = {a, b, c, NULL};

    for (int i = 0; q[i] != NULL; ++i) {
        for (char *t = q[i]; *t != '\0'; ++t)
            printf("%c ", *t);
        printf("\n");
    }

    return 0;
}
