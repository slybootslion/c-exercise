#include <stdio.h>
#include <malloc.h>


// sizeof(st) = 28
#define N 28
typedef struct {
    char name[20];
    int id;
    int score;
} st;

st *get_memory_addr() {
    st *address;

    address = (st *) malloc(N);
    if (address == NULL) {
        printf("malloc is fail!\n");
        return NULL;
    }

    return address;
}

void input_student(st *s) {
    printf("input student info:\n");
    scanf("%s%d%d", s->name, &s->id, &s->score);
}

void output_student(st *s) {
    printf("student name: %s\n", s->name);
    printf("student id: %d\n", s->id);
    printf("student score: %d\n", s->score);
}

int main() {
    st *s = get_memory_addr();
    input_student(s);
    output_student(s);
    free(s);
    s = NULL;
    return 0;
}
