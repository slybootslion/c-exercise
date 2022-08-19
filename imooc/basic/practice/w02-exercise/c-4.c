//
// Created by SlybootsLion on 2022/8/19.
//
/*
设计一个代码count_word.c，要求实现统计单词个数的功能。

1.  main()函数定义一个数组 char buf[100] = {0}.要求用户从键盘输入数据，存入buf中去
2、 设计一个count_words()函数中，要求记录buf中单词的个数
      注：要考虑以下几种情况:<1>输入的单词是否合法，若是不合法该怎么办？
                            （例如，ab#，*，12ab这些）
                           <2>以空格为单词的分割符，（若是首单词输入前就有空格该怎么办）

3、 主函数输出单词的个数.

注意： 合法的单词表示  以空格或者'\0'作为分隔符号,内容全部为字母字符。

例如：
abcd    123*31   asdf12  12*（  123  daf
合法的单词个数为2个
*/

#include <string.h>
#include "stdio.h"

int count_words(char *buf) {
    int count = 0, flag = 0, is_word = 0;
    for (int i = 0; i < strlen(buf); ++i) {
        char c = buf[i];
        if (c != ' ' && c != '\n') {
            if (flag == 0) {
                flag = 1;
                is_word = 1;
            }
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) continue;
            else is_word = 0;
        } else {
            if (flag == 1)
                count += is_word;
            flag = 0;
        }
    }
    return count;
}

int main() {
    char buf[100];
    printf("input string: \n");
    fgets(buf, 100, stdin);

    int count = count_words(buf);
    printf("words count: %d\n", count);
    return 0;
}
