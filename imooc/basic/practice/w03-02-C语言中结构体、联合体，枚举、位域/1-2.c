//
// Created by SlybootsLion on 2022/8/19.
//

#include <stdio.h>

/*
struct student{
        char name[20];
        int id;
        int score;
}st1 = {"jack",1,100};

//st在这里是全局变量
//st <===>struct student st;

int main()
{
        //int a[3];  //a[0],a[1],a[2]
        //结构体数组
        struct student st[3] = {{"rose",2,70},
                               {"lilei",3,60},
                               {"hmm",4,50}};
        int id;
        //1.要求在以上代码的基础上修改，输出st1整个人的信息。

        //2.输出st中3个的信息

        //3.要求从键盘输入一个id，判断用户输入的id，在st中是否存在。
        // 若是存在，输出整个id对应的名字。若是不存在，输出"no exist",程序结束

}
*/

struct student {
    char name[20];
    int id;
    int score;
} st1 = {"jack", 1, 100};

void print_th() {
    printf("NAME\tID\tSCORE\n");
}

void print_student(struct student st) {
    printf("%s\t%d\t%d\n", st.name, st.id, st.score);
}

void check_student(struct student *st, int id) {
    for (int i = 0; i < 3; ++i) {
        struct student s = st[i];
        if (s.id == id) {
            printf("student is %s\n", s.name);
            break;
        }
    }
    printf("no exist\n");
}


int main() {
    int a[3];
    struct student st[3] = {
            {"rose",  2, 70},
            {"lilei", 3, 60},
            {"hmm",   4, 50},
    };

    print_th();
    print_student(st1);
    for (int i = 0; i < 3; ++i)
        print_student(st[i]);

    int id;
    printf("input student id:\n");
    scanf("%d", &id);
    check_student(st, id);

    return 0;
}
