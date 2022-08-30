#include <malloc.h>
#include <string.h>

typedef int data_t;

typedef struct node {
    data_t data;
    struct node *next;
} linknode_t;

typedef struct {
    linknode_t *front;
    linknode_t *rear;
} linkqueue_t;

linkqueue_t *create_empty_linkqueue() {
    linkqueue_t *q = NULL;
    linknode_t *head = NULL;

    head = (linknode_t *) malloc(sizeof(linknode_t));
    head->next = NULL;

    q = (linkqueue_t *) malloc(sizeof(linkqueue_t));
    q->front = q->rear = head;

    return q;
}

int is_empty_linkqueue(linkqueue_t *q) {
    return q->front == q->rear;
}

void enter_linkqueue(linkqueue_t *q, data_t data) {
    linknode_t *temp = NULL;
    temp = (linknode_t *) malloc(sizeof(linknode_t));
    temp->data = data;

    temp->next = q->rear->next;
    q->rear->next = temp;

    q->rear = temp;
}

data_t delete_linkqueue(linkqueue_t *q) {
    linknode_t *temp = NULL;
    data_t data;

    temp = q->front->next;
    data = temp->data;

    q->front->next = temp->next;
    free(temp);
    temp = NULL;

    if (q->front->next == NULL)
        q->rear = q->front;

    return data;
}

int main() {
    linkqueue_t *q = NULL;

    q = create_empty_linkqueue();
    for (int i = 0; i < 10; ++i) {
        enter_linkqueue(q, i);
    }
    while (!is_empty_linkqueue(q)) {
        printf("%d ", delete_linkqueue(q));
    }
    printf("\n");

    return 0;
}
