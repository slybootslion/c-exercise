#include <stdio.h>

/*
char a1[] = "abcde";
char a2[] = "XYZBBQ";

char *p_array[] = {a1,a2,NULL};

1.要求把通过p_array把a1所有所有小写字符换成大写字符.
2.要求把通过p_array把a2所有所有大写字符换成小写字符.
3. 输出a1和a2字符串的数据观察效果.
 * */

int main() {
    char a1[] = "abcde";
    char a2[] = "XYZBBQ";
    char *p_array[] = {a1, a2, NULL};

    int len = sizeof(p_array) / sizeof(p_array[0]);
    for (int i = 0; i < len; ++i) {
        if (p_array[i] == NULL) break;
        for (char *j = p_array[i]; *j != '\0'; j++) {
            char c = *j;
            c >= 'A' && c <= 'Z' ? c += 32 : (c -= 32);
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
