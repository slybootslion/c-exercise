//
// Created by SlybootsLion on 2022/9/8.
//
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

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

    if (q->front->next == NULL)
        q->rear = q->front;

    return data;
}

typedef int vertex_t;

#define N 9

typedef struct {
    vertex_t v[N];
    int maxtrix[N][N];
} graph_t;

int visited[N];

graph_t *create_graph() {
    graph_t *g = (graph_t *) malloc(sizeof(graph_t));
    memset(g, 0, sizeof(graph_t));

    for (int i = 0; i < N; ++i)
        g->v[i] = i;

    return g;
}

void input_edge(graph_t *g) {
    int i, j;
    printf("please input link (v0,v1) (v0,v2)...\n");
    while (scanf("(V%d,V%d)", &i, &j) == 2) {
        g->maxtrix[i][j] = g->maxtrix[j][i] = 1;
        getchar();
    }
    while (getchar() != '\n');
}

void print_matrix(graph_t *g) {
    printf("%3c", ' ');
    for (int i = 0; i < N; ++i)
        printf("V%-2d", i);
    putchar('\n');

    for (int i = 0; i < N; ++i) {
        printf("V%-2d", i);
        for (int j = 0; j < N; ++j)
            printf("%-3d", g->maxtrix[i][j]);
        putchar('\n');
    }
}

int first_adj(graph_t *g, int v) {
    for (int i = 0; i < N; ++i) {
        if (g->maxtrix[v][i] != 0)
            return i;
    }
    return -1;
}

int next_adj(graph_t *g, int v, int u) {
    for (int i = u + 1; i < N; ++i) {
        if (g->maxtrix[v][i] != 0)
            return i;
    }
    return -1;
}

void DFS(graph_t *g, int v) {
    printf("V%-d->", v);
    visited[v] = 1;

    int u = first_adj(g, v);
    while (u >= 0) {
        if (visited[u] == 0)
            DFS(g, u);
        u = next_adj(g, v, u);
    }
}

void BFS(graph_t *g, int v) {
    linkqueue_t *q = create_empty_linkqueue();
    visited[v] = 1;
    enter_linkqueue(q, v);
    while (!is_empty_linkqueue(q)) {
        int t = delete_linkqueue(q);
        printf("V%-3d->", t);

        for (int i = 0; i < N; ++i) {
            if (g->maxtrix[t][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enter_linkqueue(q, i);
            }
        }
    }
}

int main() {
    graph_t *g = NULL;

    g = create_graph();
    input_edge(g);
    print_matrix(g);
//    DFS(g, 0);
//    putchar('\n');
    BFS(g, 0);
    putchar('\n');
    return 0;
}
