#include <stdio.h>
#include <malloc.h>

//
// Created by SlybootsLion on 2022/9/6.
//
typedef int vertex_t;

#define N 5

typedef struct {
    vertex_t v[N];
    int matrix[N][N];
} grapht_t;

grapht_t *create_graph() {
    grapht_t *g = NULL;
    g = (grapht_t *) malloc(sizeof(grapht_t));
    for (int i = 0; i < N; ++i)
        g->v[i] = i;
    return g;
}

void input_edge(grapht_t *g) {
    int i = 0, j = 0;
    printf("input edge like (v0, v1) (v0, v2) ...\n");
    while (scanf("(V%d, V%d)", &i, &j) == 2) {
        g->matrix[i][j] = g->matrix[j][i] = 1;
        getchar();
    }
    while (getchar() != '\n');
}

void print_matrix(grapht_t *g) {
    printf("%3c", ' ');
    for (int i = 0; i < N; ++i)
        printf("V%-2d", i);
    putchar('\n');
    for (int i = 0; i < N; ++i) {
        printf("v%-2d", i);
        for (int j = 0; j < N; ++j)
            printf("%-3d", g->matrix[i][j]);
        putchar('\n');
    }
}

int main() {
    grapht_t *g = create_graph();
    input_edge(g);
    print_matrix(g);
    return 0;
}
