//
// Created by SlybootsLion on 2022/8/22.
//

#include <stdio.h>
#include <malloc.h>

/*
typedef struct
{
    char name[20];
    int id;
    int score;
}s_t;

1. 设计一个s_t *get_memeory_addr()函数,要求在堆区为上述结构体分配空间。
2. 设计一个void input_student(s_t *s)函数，要求用户从键盘输入数据给s中的变量。
3. 设计一个void optput_student(s_t *s)函数，要求输出用户输入的数据。
4. 设计一个main()函数调用上述数据。
 * */
typedef struct {
    char name[20];
    int id;
    int score;
} st;

st *get_memory_addr() {
    st *addr = (st *) malloc(sizeof(st));
    if (addr == NULL) {
        printf("malloc is fail\n");
        return NULL;
    }
    return addr;
}

void input_student(st *s) {
    printf("input student info: [name id score]\n");
    scanf("%s%d%d", s->name, &s->id, &s->score);
}

void output_student(st *s) {
    printf("student name: %s\n", s->name);
    printf("student id: %d\n", s->id);
    printf("student score %d\n", s->score);
}

int main() {
    st *s = get_memory_addr();
    input_student(s);
    output_student(s);
    return 0;
}
