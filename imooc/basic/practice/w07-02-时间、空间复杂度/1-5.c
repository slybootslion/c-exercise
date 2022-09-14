#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Stack {
    int buf[500];
    int top;
} stack_t;

stack_t *create_empty_stack() {
    stack_t *s = (stack_t *) malloc(sizeof(stack_t));
    memset(s, 0, sizeof(stack_t));
    s->top = -1;
    return s;
}

int is_empty_stack(stack_t *s) {
    return s->top == -1;
}

void push_stack(stack_t *s, int data) {
    s->buf[s->top] = data;
    s->top++;
}

int pop_stack(stack_t *s) {
    int r = s->buf[s->top];
    s->top--;
    return r;
}

int get_top_data(stack_t *s) {
    return s->buf[s->top];
}

// 下面这些发布就可以了 上面都是链表操作

int to_num(const char *str, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

int check_priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void calculate_handle(stack_t *s1, stack_t *s2, char op) {
    if (is_empty_stack(s2)) {
        if (op != '0')
            push_stack(s2, op);
        return;
    }
    int pre_op = get_top_data(s2);
    printf("%c\n", pre_op);
    if (check_priority((char) pre_op) < check_priority(op)) {
        push_stack(s2, op);
    } else {
        int n1 = pop_stack(s1);
        int n2 = pop_stack(s1);
        char op_s = (char) pop_stack(s2);
        int res = 0;
        switch (op_s) {
            case '+':
                res = n1 + n2;
                break;
            case '-':
                res = n1 - n2;
                break;
            case '*':
                res = n1 * n2;
                break;
            case '/':
                res = n1 / n2;
                break;
            default:
                break;
        }
        push_stack(s1, res);
        calculate_handle(s1, s2, op);
    }
}


int main() {
    char buf[1024];
    int data = 0;

    printf("输入算式：\n");
    scanf("%s", buf);

    stack_t *stack1 = create_empty_stack();
    stack_t *stack2 = create_empty_stack();

    char *p = buf;
    char num_str[80];
    int c = 0;
    while (*p != '\0') {
        if (*p >= '0' && *p <= '9') {
            num_str[c] = *p;
            c++;
            if (*(p + 1) < '0' || *(p + 1) > '9')
                push_stack(stack1, to_num(num_str, c));
            p++;
            continue;
        } else {
            c = 0;
            calculate_handle(stack1, stack2, *p);
            p++;
            continue;
        }
    }
    printf("%d\n", get_top_data(stack1));
    return 0;
}
