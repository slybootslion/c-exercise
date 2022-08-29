//
// Created by SlybootsLion on 2022/8/29.
//
#include <stdio.h>

#define MAX 10

//实际学⽣的存储
typedef struct student datatype_t;
struct student {
    char name[20];
    int id;
    int age;
};
typedef struct students {
    datatype_t buf[MAX]; //定义数组记录班级学⽣每个学⽣的信息。
    int n; //学⽣实际到来的个数。
} seqlist_t;

static int get_first(seqlist_t *t) {
    return t->buf[0].id;
}

int main() {
    seqlist_t arr = {{"lilei", 1, 18, "hanmeimei", 2, 18}, 2};
    int first_id = get_first(&arr);
    printf("first student id is %d\n", first_id);
    return 0;
}
