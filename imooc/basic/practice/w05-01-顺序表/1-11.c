//
// Created by SlybootsLion on 2022/8/29.
//
#include <malloc.h>
#include <string.h>

#define MAX 3

//实际学生的存储
struct student {
    char name[20];
    int id;
    int age;
};
typedef struct student datatype_t;

typedef struct {
    datatype_t buf[MAX]; //定义数组记录班级学生每个学生的信息。
    int n; //学生实际到来的个数。
} seqlist_t;

int is_empty_seqlist(seqlist_t *l);

int delete_data_seqlist(seqlist_t *l, int id);

seqlist_t *create_empty_seqlist() {
    seqlist_t *l = malloc(sizeof(seqlist_t));
    if (l == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    memset(l, 0, sizeof(seqlist_t));
    l->n = 0;
    return l;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data) {
    l->buf[l->n] = data;
    l->n++;
}

void printf_data_seqlist(seqlist_t *l) {
    printf("id\tname\tage\n");
    for (int i = 0; i < l->n; ++i)
        printf("%d\t%s\t%d\n", l->buf[i].id, l->buf[i].name, l->buf[i].age);
    putchar('\n');
}

int main() {
    struct student st[] = {
            {"lilei", 1, 18},
            {"hmm",   2, 19},
            {"jim",   3, 18},
    };

    seqlist_t l = *create_empty_seqlist();
    for (int i = 0; i < sizeof(st) / sizeof(st[0]); ++i)
        insert_data_seqlist(&l, st[i]);
    printf_data_seqlist(&l);

    printf("==================================\n");
    printf("input you want to del student's id\n");

    int id;
    scanf("%d", &id);
    delete_data_seqlist(&l, id);

    printf_data_seqlist(&l);

    return 0;
}

int is_empty_seqlist(seqlist_t *l) {
    return l->n <= 0 ? 1 : 0;
}

int delete_data_seqlist(seqlist_t *l, int id) {
    if (is_empty_seqlist(l))
        return -1;
    int j = 0, i = 0;
    for (i = 0; i < l->n; ++i) {
        if (l->buf[i].id != id) {
            l->buf[j] = l->buf[i];
            j++;
        }
    }
    l->n = j;
    if (i == j)
        return -2;
    else
        printf("delete id %d student is successful!\n", id);
    return 0;
}
