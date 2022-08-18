#include "stdio.h"
#include "string.h"

// strcat 字符串连接函数
int main() {
    char word[20];
    char explain[20];
    char sql[50];

    printf("please input you select word: ");
    fgets(word, 20, stdin);

    printf("please input word explain: ");
    fgets(explain, 20, stdin);

    strcpy(sql, word);
    strcat(sql, explain);

    printf("%s\n", sql);

    return 0;
}
