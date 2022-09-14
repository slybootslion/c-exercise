//
// Created by SlybootsLion on 2022/9/14.
//
#include <tgmath.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode *node, int i) {
    if (!node)
        return i;
    int l = dfs(node->left, i + 1);
    int r = dfs(node->right, i + 1);
    return fmax(l, r);
}

int maxDeep(struct TreeNode *root){
    int level = 0;
    int max = dfs(root, level);
    return max;
}
