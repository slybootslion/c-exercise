//
// Created by SlybootsLion on 2022/9/28.
//

#include "bitree.h"
#include "linkstack.h"

bitree_t *create_binary_tree(int n) {
  bitree_t *root = (bitree_t *) malloc(sizeof(bitree_t));
  memset(root, 0, sizeof(bitree_t));
  root->n = n;
  root->lchild = root->rchild = NULL;

  printf("input %d node data:", n);
  scanf("%c", &(root->data));

  while (getchar() != '\n');

  if (2 * n <= N)
    root->lchild = create_binary_tree(2 * n);

  if (2 * n + 1 <= N)
    root->rchild = create_binary_tree(2 * n + 1);

  return root;
}

void pre_order(bitree_t *root) {
  if (NULL == root)
    return;

  linkstack_t *s = create_empty_linkstack();
  bitree_t *temp = root;

  while (temp != NULL || !is_empty_linkstack(s)) {
    while (temp != NULL) {
      printf("(%d: %c) ", temp->n, temp->data);
      push_linkstack(s, temp);
      temp = temp->lchild;
    }

    if (!is_empty_linkstack(s)) {
      temp = pop_linkstack(s);
      temp = temp->rchild;
    }
  }

  free(s);
}

void in_order(bitree_t *root) {
  if (NULL == root)
    return;

  linkstack_t *s = create_empty_linkstack();

  bitree_t *temp = root;

  while (temp != NULL || !is_empty_linkstack(s)) {
    if (temp != NULL) {
      push_linkstack(s, temp);
      temp = temp->lchild;
    } else {
      temp = pop_linkstack(s);
      printf("(%d: %c) ", temp->n, temp->data);
      temp = temp->rchild;
    }
  }

  free(s);
}

void post_order(bitree_t *root) {
  if (NULL == root)
    return;

  linkstack_t *s = create_empty_linkstack();
  bitree_t *cur = NULL;
  bitree_t *pre = NULL;

  push_linkstack(s, root);

  while (!is_empty_linkstack(s)) {
    cur = get_top_data(s);
    //以下情况，可以直接输出值:
    //1.左右孩子都为空
    //2.左右孩子存在，并且左孩子或右孩子都被访问过来。
    if (cur->lchild == NULL && cur->rchild == NULL || \
      (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
      printf("(%d: %c) ", cur->n, cur->data);
      pop_linkstack(s);
      pre = cur;
    } else {
      if (cur->rchild != NULL)
        push_linkstack(s, cur->rchild);
      if (cur->lchild != NULL)
        push_linkstack(s, cur->lchild);
    }
  }

  free(s);
}
