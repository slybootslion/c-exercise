//
// Created by SlybootsLion on 2022/8/19.
//
#include <stdio.h>

/*
typedef struct
{
    char name[20];
    int id;
    int score;
}s_t;

int main()
{
    s_t   s[3];
    //要求设计一个input_student()函数，参数自己设计，用户从键盘输入3个学生的信息存放s中
    //然后设计一个ouput_student()函数，参数自己设计，输出3个学生的信息存放s中
    //最后设计一个maxscore_student()函数，参数自己设计，返回3个学生中，分数最高人的信息。
}
*/

typedef struct {
    char name[20];
    int id;
    int score;
} s_t;

void input_student(s_t *s) {
    printf("input 3 students info [name id score]:\n");
    for (int i = 0; i < 3; ++i) {
        // s_t st = s[i]; 不能这样用，否则后面打印出来不对，不太能理解。 --> 问问
        scanf("%s%d%d", s[i].name, &s[i].id, &s[i].score);
    }
}

void output_student(s_t *s) {
    printf("NAME\tID\tSCORE\n");
    for (int i = 0; i < 3; ++i) {
        s_t st = s[i];
        printf("%s\t%d\t%d\n", st.name, st.id, st.score);
    }
}

s_t max_score_student(s_t *s) {
    s_t max_t;
    for (int i = 0; i < 3; ++i) {
        if (i == 0){
            max_t = s[i];
            continue;
        }
        if (s[i].score > max_t.score)
            max_t = s[i];
    }
    return max_t;
}


int main() {
    s_t s[3];
    input_student(s);
    s_t st = max_score_student(s);
    printf("max score student is : %s\t%d\t%d\n", st.name, st.id, st.score);
    return 0;
}
