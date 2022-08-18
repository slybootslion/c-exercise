#include "stdio.h"
#include "string.h"

// strcpy 字符串拷贝函数
int main() {
    char buf[20] = {'h', 'e', 'l', 'l', 'o', '\0'};
    strcpy(buf, "QQ");
    for (int i = 0; i < 20; ++i) {
        printf("%c: %d\n", buf[i], buf[i]);
    }
    printf("buf = %s\n", buf);
    return 0;
}
