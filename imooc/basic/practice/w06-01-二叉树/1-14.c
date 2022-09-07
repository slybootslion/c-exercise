//
// Created by SlybootsLion on 2022/9/5.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *code;
    unsigned long size;
} huff_buf, *huff_bufp;

typedef struct HuffListNode huff_list_node, *huff_list_nodep;
typedef struct HuffNode huff_node, *huff_nodep;
typedef struct HuffCode huff_code, *huff_codep;

struct HuffNode {
    int key;
    int weight;
    huff_nodep left;
    huff_nodep right;
};

struct HuffListNode {
    huff_nodep node;
    huff_list_nodep next;
};

struct HuffCode {
    char *code;
    int size;
};

typedef struct {
    huff_nodep root;
    huff_codep codes[256];
    int size;
} huff_tree, *huff_treep;

typedef struct {
    char *code;
    huff_treep tree;
} huff_result, *huff_resultp;

typedef struct {
    huff_list_nodep head;
    int keys[256];
    int size;
} huff_list, *huff_listp;

huff_nodep make_huff_node(int key, int weight) {
    huff_nodep res = (huff_nodep) malloc(sizeof(huff_node));
    res->key = key;
    res->weight = weight;
    res->left = res->right = NULL;
    return res;
}

huff_listp make_huff_list() {
    huff_listp res = (huff_listp) malloc(sizeof(huff_list));
    res->head = NULL;
    memset(res->keys, 0, sizeof(res->keys[0]) * 256);
    res->size = 0;
    return res;
}

int insert_huff_node(huff_listp list, huff_nodep node) {
    if (list == NULL || node == NULL || node->weight <= -256)
        return 0;
    huff_list_nodep cur = list->head;
    huff_list_nodep *rootp = &(list->head);
    huff_list_nodep *last = NULL;
    huff_list_nodep temp = (huff_list_nodep) malloc(sizeof(huff_list_node));
    temp->node = node;
    temp->next = NULL;
    if (node->key >= 0 && node->key < 256)
        list->keys[node->key] = node->weight;
    list->size++;

    for (; cur != NULL && cur->node->weight < node->weight; cur = cur->next) {
        last = rootp;
        rootp = &(cur->next);
    }

    temp->next = cur;
    if (last == NULL)
        list->head = temp;
    else
        (*last)->next = temp;

    return 1;
}

huff_listp get_huff_list(huff_bufp buf) {
    if (buf == NULL || buf->code == NULL)
        return NULL;
    huff_listp list = make_huff_list();
    for (int i = 0; buf->code[i] != '\0'; ++i) {
        unsigned char ch = buf->code[i];
        list->keys[ch]++;
    }
    for (int i = 0; i < 256; ++i) {
        if (list->keys[i] > 0)
            insert_huff_node(list, make_huff_node(i, list->keys[i]));
    }
    return list;
}

huff_nodep shift_huff_node(huff_listp list) {
    if (list == NULL || list->head == NULL)
        return NULL;
    huff_nodep res = list->head->node;
    huff_list_nodep next = list->head->next;
    free(list->head);
    list->head = next;
    list->size--;
    return res;
}

huff_treep gen_huff_codes(huff_treep tree, huff_nodep node, char codes[], int idx) {
    if (tree == NULL || node == NULL)
        return NULL;
    if (node->left == NULL && node->right == NULL) {
        int key = node->key;
        huff_codep code = (huff_codep) malloc(sizeof(huff_code));
        code->code = (char *) malloc(idx + 1);
        code->size = idx;
        memcpy(code->code, codes, code->size);
        code->code[code->size] = '\0';
        tree->codes[key] = code;
    }
    codes[idx] = '1';
    gen_huff_codes(tree, node->right, codes, idx + 1);
    codes[idx] = '0';
    gen_huff_codes(tree, node->left, codes, idx + 1);
    return tree;
}

huff_treep make_huff_tree(huff_listp list) {
    huff_treep tree = (huff_treep) malloc(sizeof(huff_tree));
    tree->root = NULL;
    tree->size = 0;
    memset(tree->codes, 0, sizeof(tree->codes));

    huff_nodep a, b, c;
    tree->size = 2 * list->size - 1;
    while (list->size > 1) {
        a = shift_huff_node(list);
        b = shift_huff_node(list);
        c = make_huff_node(-256, a->weight + b->weight);
        c->left = a;
        c->right = b;
        insert_huff_node(list, c);
    }
    tree->root = c;
    char codes[8092];
    return gen_huff_codes(tree, tree->root, codes, 0);
}

huff_codep get_huff_code(huff_treep tree, int key) {
    if (key < 256 && key >= 0 && tree->codes[key] > 0)
        return tree->codes[key];
    return NULL;
}

huff_resultp huffman_encoding(huff_bufp buf) {
    huff_resultp result = (huff_result *) malloc(sizeof(huff_result));
    result->code = NULL;

    if (buf == NULL) return NULL;

    huff_listp list = get_huff_list(buf);

    result->tree = make_huff_tree(list);
    int len = 0;
    for (int i = 0; buf->code[i] != '\0'; ++i) {
        int key = (unsigned char) buf->code[i];
        huff_codep code = get_huff_code(result->tree, key);
        if (code == NULL)
            return NULL;
        len += code->size;
    }
    result->code = (char *) malloc(len + 1);
    result->code[0] = '\0';

    for (int i = 0; buf->code[i] != '\0'; ++i) {
        unsigned char key = buf->code[i];
        huff_codep code = get_huff_code(result->tree, key);
        strncat(result->code, code->code, code->size);
    }

    return result;
}

huff_bufp huffman_decoding(huff_resultp result) {
    if (result == NULL || result->code == NULL || result->tree == NULL)
        return NULL;
    huff_treep tree = result->tree;
    char *code = result->code;
    int len = 0;
    for (int i = 0; code[i] != '\0';) {
        huff_nodep root = tree->root;
        while (root->left != NULL && root->right != NULL && code[i] != '\0') {
            root = (code[i] == '0' ? root->left : root->right);
            i++;
        }
        if ((root->left != NULL || root->right != NULL) && code[i] == '\0')
            return NULL;
        len++;
    }

    huff_bufp res = (huff_bufp) malloc(sizeof(huff_buf));
    res->code = (char *) malloc(len + 1);
    res->code[0] = '\0';
    res->size = len;

    int idx = 0;
    for (int i = 0; code[i] != '\0';) {
        huff_nodep root = tree->root;
        while (root->left != NULL && root->right != NULL && code[i] != '\0') {
            root = (code[i] == '0' ? root->left : root->right);
            i++;
        }
        res->code[idx++] = root->key;
    }
    res->code[idx] = '\0';
    return res;
}

int main() {
    char b[] = "ADDCDCCBCDDBDDD";
    printf("origin string is: %s\n", b);

    huff_bufp buf = (huff_bufp) malloc(sizeof(huff_buf));

    buf->code = &b[0];
    buf->size = strlen(buf->code);
    huff_resultp result = huffman_encoding(buf);    //获取编码结果
    printf("huffman encode is: %s\n", result->code);

    huff_bufp origin = huffman_decoding(result); //通过编码获取原始数据
    printf("huffman decode is: %s\n", origin->code);
    return 0;
}

// https://www.codeleading.com/article/36796086952/
// https://zh.m.wikipedia.org/zh-tw/%E9%9C%8D%E5%A4%AB%E6%9B%BC%E7%BC%96%E7%A0%81
