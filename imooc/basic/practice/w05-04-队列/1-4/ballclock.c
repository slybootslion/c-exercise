//
// Created by SlybootsLion on 2022/8/31.
//
#include "head.h"

void print_linklist(linknode_t *head) {
    linknode_t *p = head->next;

    while (p) {
        printf("%-3d\t", p->data); // 以整数形式左对齐输出三个字符（包括空格）
        p = p->next;
    }
    putchar('\n');
}

int is_orginal_queue(linkqueue_t *q) {
    linknode_t *p = q->front->next;
    for (int i = 0; i <= N; ++i) {
        if (i != p->data)
            return 0;
        p = p->next;
    }
    return 1;
}

int ball_clock() {
    linkstack_t *min_stack = NULL,
            *min5_stack = NULL,
            *hour_stack = NULL;
    linkqueue_t *ball_queue = NULL;
    int half_day = 0;
    int ball = 0;

    min_stack = create_empty_linkstack();
    min5_stack = create_empty_linkstack();
    hour_stack = create_empty_linkstack();
    ball_queue = create_empty_linkqueue();

    for (ball = 0; ball <= N; ++ball) {
        enter_linkqueue(ball_queue, ball);
    }

    print_linklist(ball_queue->front);

    while (1) {
        ball = delete_linkqueue(ball_queue);
        if (min_stack->n < 4) {
            push_linkstack(min_stack, ball);
            continue;
        }

        while (!is_empty_linkstack(min_stack))
            enter_linkqueue(ball_queue, pop_linkstack(min_stack));

        if (min5_stack->n < 11) {
            push_linkstack(min5_stack, ball);
            continue;
        }

        while (!is_empty_linkstack(min5_stack))
            enter_linkqueue(ball_queue, pop_linkstack(min5_stack));

        if (hour_stack->n < 11) {
            push_linkstack(hour_stack, ball);
            continue;
        }

        while (!is_empty_linkstack(hour_stack))
            enter_linkqueue(ball_queue, pop_linkstack(hour_stack));

        enter_linkqueue(ball_queue, ball);

        half_day++;

        if (is_orginal_queue(ball_queue))
            break;
    }

    return half_day / 2;
}

int main() {
    int day_count = 0;

    day_count = ball_clock();

    printf("restoring orignal queue need %d days\n", day_count);

    return 0;
}
