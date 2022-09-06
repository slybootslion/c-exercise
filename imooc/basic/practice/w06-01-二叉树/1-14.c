//
// Created by SlybootsLion on 2022/9/5.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 100  /* 编码函数中，被编译的字符串的最大长度 */
#define max 100  /* 最大字符的个数 */

typedef struct {
    char data;
    int weight;
    int parent;
    int left;
    int right;
} huff_node;

typedef struct {
    char cd[max];
    int start;
} huff_code;

huff_node *count_char(const int count[]) {
    static huff_node hn[2 * max];
    hn[0].weight = 27;
    for (int i = 0; i < 27; ++i) {
        hn[i].data = (char) ('A' + i - 1);
        hn[i].weight = count[i - 1];
    }
    return hn;
}

void huffman_tree(huff_node *hn) {
    int n = hn[0].weight;
    for (int i = 0; i <= 2 * n - 1; ++i)
        hn[i].parent = hn[i].left = hn[i].right = 0;
    for (int i = n + 1; i <= n * 2 - 1; ++i) {
        int m1 = 10000, m2 = 10000, x1 = 0, x2 = 2;
        for (int j = 1; j < i - 1; ++j) {
            if (hn[j].parent == 0) {
                if (hn[j].weight < m1) {
                    m2 = m1;
                    x2 = x1;
                    m1 = hn[j].weight;
                    x1 = j;
                } else if (hn[j].weight < m2) {
                    m2 = hn[j].weight;
                    x2 = j;
                }
            }
        }
        hn[x1].parent = i;
        hn[x2].parent = i;
        hn[i].weight = hn[x1].weight + hn[x2].weight;
        hn[i].left = x1;
        hn[i].right = x2;
    }
}

huff_code *print_huffman_code(huff_node *hn) {
    static huff_code hc[max];
    huff_code d;
    int n = hn[0].weight;
    int c = 0, f;
    for (int i = 0; i <= n; ++i) {
        d.start = n + 1;
        c = i;
        f = hn[i].parent;
        while (f != 0) {
            if (hn[f].left == c)
                d.cd[--d.start] = '0';
            else
                d.cd[--d.start] = '1';
            c = f;
            f = hn[f].parent;
        }
        hc[i] = d;
    }
    printf("huffman code table:\n");
    for (int i = 1; i <= n; ++i) {
        printf("%c:", hn[i].data);
        int x = hc[i].start;
        for (int k = x; k <= n; ++k)
            printf("%c", hc[i].cd[k]);
        putchar('\n');
    }
    return hc;
}

huff_node *encoding(huff_code *hc, huff_node *hn, char in[]) {
    int j, m = 0, k, x;
    char out[2 * maxsize];
    int count[26] = {0};
    unsigned long n = strlen(in);

    for (int i = 0; i < n; ++i)
        count[in[i] - 'A']++;

    hn = count_char(count);
    huffman_tree(hn);
    hc = print_huffman_code(hn);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= hn[0].weight; ++j) {
            if (in[i] == hn[j].data) {
                x = hc[j].start;
                for (int k = x; k <= hn[0].weight; ++k)
                    out[m++] = hc[j].cd[k];
            }
        }
    }

    printf("encoding result is: \n");
    for (int i = 0; i < m; ++i)
        printf("%c", out[i]);

    return hn;
}

int main() {
    char b[] = "ADDCDCCBCDDBDDD";
    huff_node *h_node = NULL;
    huff_code *h_code = NULL;
    h_node = encoding(h_code, h_node, b);
    h_code = print_huffman_code(h_node);

    return 0;
}

// https://www.codeleading.com/article/36796086952/
