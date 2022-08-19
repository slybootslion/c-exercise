#include <string.h>
#include <stdio.h>

//
// Created by SlybootsLion on 2022/8/19.
//
/*
struct student {
    char name[20];
    int id;
    int score;
};

int main() {
    struct student st;
    struct student *sp = &st;

    strcpy(st.name, "jack");
    st.score = 100;
    (&st)->id = 1;

    printf("NAME\tID\tSCORE\n");
    printf("%s\t%d\t%d\n", st.name, st.id, st.score);

    return 0;
}
*/

/*
struct student {
    char name[20];
    int id;
    int score;
}st;

int main() {
    struct student *sp = &st;

    strcpy(st.name, "jack");
    sp->id = 1;
    sp->score = 80;

    printf("NAME\tID\tSCORE\n");
    printf("%s\t%d\t%d\n", st.name, st.id, st.score);

    return 0;
}
*/

struct student {
    char name[20];
    int id;
    int score;
}st = {"rose", 2, 100};

int main() {
    printf("NAME\tID\tSCORE\n");
    printf("%s\t%d\t%d\n", st.name, st.id, st.score);

    return 0;
}
