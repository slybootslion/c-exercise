#include <stdio.h>


/*
 char buf[100] = {0};
要求用户从键盘输入字符数串存放到buf中,若是用户输入的字符数组中存在大写字符,
则转换为小写字符,若是小写字符则不管,然后输出用户输入的数据
 * */
int main() {
    char buf[100];
    printf("input string:\n");
    scanf("%s", buf);

    for (int i = 0; i < 100; ++i) {
        char c = buf[i];
        if (c == '\0') break;
        if (c >= 'A' && c <= 'Z')
            c += 32;
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
