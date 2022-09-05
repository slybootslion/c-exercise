//
// Created by SlybootsLion on 2022/9/5.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char data;
    int weight;
    int parent;
    int left;
    int right;
} huff_node;

typedef struct {
    char code[1000];
    int start;
}huff_code;

huff_code *encoding(huff_code *h_code, huff_node *h_node) {
    int i, j, n, m, k, x;
    char in[1000], out[2000];
    int count[27] = {0};
    return h_node;
}

int main () {
    char b[ ] = "ADDCDCCBCDDBDDD";
    huff_code *h_code;
    huff_node *h_node;

    return 0;
}


// https://www.codeleading.com/article/36796086952/
