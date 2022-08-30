//
// Created by SlybootsLion on 2022/8/30.
//
#include <malloc.h>

#define MAX 12

typedef struct {
    char buf[MAX];
    int top;
} stack;

stack *create_empty_stack() {
    stack *s = malloc(sizeof(stack));
    s->top = -1;
    return s;
}

int is_empty(stack *s) {
    return s->top == -1 ? 1 : 0;
}

int is_full(stack *s) {
    return s->top == MAX - 1 ? 1 : 0;
}

void push_stack(stack *s, char data) {
    s->buf[s->top] = data;
    s->top++;
}

char pop_stack(stack *s) {
    s->top--;
    return s->buf[s->top];
}

char get_top_data(stack *s) {
    return s->buf[s->top];
}

int main() {
    char data[] = {'a', 'n', 'i', 'h', 'c', ' ', 'e', 'v', 'o', 'l', ' ', 'I'};
    char res;

    stack *s = create_empty_stack();
    for (int i = 0; i < MAX; ++i)
        push_stack(s, data[i]);

    while (!is_empty(s)) {
        res = pop_stack(s);
        printf("%c", res);
    }
    putchar('\n');

    return 0;
}
