#include <stdio.h>
#include <string.h>

int count_words(const char *arr) {
    int count = 0, flag = 0, is_word = 1;
    for (int i = 0; i < strlen(arr); ++i) {
        char c = arr[i];
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
    printf("input a string:\n");
    fgets(buf, 100, stdin);

    int count = count_words(buf);
    printf("words count is: %d\n", count);
    return 0;
}
