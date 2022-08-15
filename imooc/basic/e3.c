#include <stdio.h>
#include <string.h>

void input_data(char *str) {
    printf("input integer string:\n");
    scanf("%s", str);
}

int str_to_int(char *str) {
    int num = 0;
    for (int i = 0; i < strlen(str); ++i) {
        num = 10 * num + str[i] - '0';
    }
    return num;
}

int main() {
    char arr[100];
    input_data(arr);
    int integer = str_to_int(arr);
    printf("%d\n", integer);
    return 0;
}
