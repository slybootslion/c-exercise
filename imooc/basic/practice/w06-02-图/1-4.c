//
// Created by SlybootsLion on 2022/9/7.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int vertex_t;

#define N 9

typedef struct {
    vertex_t v[N];
    int matrix[N][N];
} grapht_t;

int visited[N];

grapht_t *create_graph() {
    grapht_t *g = NULL;
    g = (grapht_t *) malloc(sizeof(grapht_t));
    if (g == NULL) {
        g = (grapht_t *) malloc(sizeof(grapht_t));
        printf("%s: mallco is fail\n", __FUNCTION__);
        return NULL;
    }
    memset(g, 0, sizeof(grapht_t));

    for (int i = 0; i < N; ++i)
        g->v[i] = i;

    return g;
}

void input_edge(grapht_t *g) {
    int ret = 0;
    printf("please input (V0, V1)(V0, V1)...:\n");
    int i, j;
    // scanf()函数返回的值为：正确按指定格式输入变量的个数；也即能正确接收到值的变量个数。
    while (scanf("(V%d,V%d)", &i, &j) == 2) {
        getchar();
        g->matrix[i][j] = g->matrix[j][i] = 1;
    }
    while (getchar() != '\n');
}

void print_matrix(grapht_t *g) {
    printf("%3c", ' ');
    for (int i = 0; i < N; ++i)
        printf("%-2d", i); // -左对齐 2两位
    putchar('\n');

    for (int i = 0; i < N; ++i) {
        printf("V%-2d", i);
        for (int j = 0; j < N; ++j)
            printf("%-3d", g->matrix[i][j]);
        putchar('\n');
    }
}

int first_adj(grapht_t *g, int v) {
    for (int i = 0; i < N; ++i) {
        if (g->matrix[v][i] != 0)
            return i;
    }
    return -1;
}

int next_adj(grapht_t *g, int v, int u) {
    for (int i = u + 1; i < N; ++i) {
        if (g->matrix[v][i] != 0)
            return i;
    }
    return -1;
}

void DFS(grapht_t *g, int v) {
    printf("V%-3d", v);
    visited[v] = 1;

    int u = first_adj(g, v);

    while (u >= 0) {
        if (visited[u] == 0)
            DFS(g, u);
        u = next_adj(g, v, u);
    }
}

int main() {
    grapht_t *g = create_graph();

    input_edge(g);
    print_matrix(g);

    DFS(g, 0);
    putchar('\n');
    return 0;
}

