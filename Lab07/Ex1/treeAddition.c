#include "treeAddition.h"
#include "treePrivate.h"
#include "treePublic.h"
#include <stdio.h>

int l = 0;

void countNode(node_t *root, int *array) {

  if (root->left == NULL && root->right == NULL) {
    array[0]++;
    return;
  }

  if ((root->left == NULL && root->right != NULL) ||
      (root->right == NULL && root->left != NULL)) {
    array[1]++;
    if (root->left != NULL) {
      countNode(root->left, array);
    } else
      countNode(root->right, array);
  }

  if (root->left != NULL && root->right != NULL) {
    array[2]++;
    countNode(root->right, array);
    countNode(root->left, array);
  }
  return;
}

void countLevel(node_t *root, int *array, int l) {
  if (root->left == NULL && root->right == NULL) {
    array[l]++;
    l--;
    return;
  }

  if ((root->left == NULL && root->right != NULL) ||
      (root->right == NULL && root->left != NULL)) {
    if (root->left != NULL) {
      array[l]++;
      l++;
      countLevel(root->left, array, l);
    } else {
      countLevel(root->right, array, l);
    }
  }

  if (root->left != NULL && root->right != NULL) {
    array[l]++;
    l++;
    countLevel(root->left, array, l);
    countLevel(root->right, array, l);
  }
}

void countPath(node_t *root, int *np, int *length) {
  if (root->left == NULL && root->right == NULL) {
    (*length)++;
    l--;
    (*np)++;
    return;
  }

  if ((root->left == NULL && root->right != NULL) ||
      (root->right == NULL && root->left != NULL)) {
    if (root->left != NULL) {
      l++;
      (*length)++;
      countPath(root->left, np, length);
    } else {
      (*length)++;
      countPath(root->right, np, length);
    }
  }

  if (root->left != NULL && root->right != NULL) {
    l++;
    (*length)++;
    *length = l + *length;
    countPath(root->left, np, length);
    (*length)++;
    *length = l + *length;
    countPath(root->right, np, length);
  }
}

int visit(node_t *root, int key1, int key2) {
  int d = 0;
  node_t *a = root;
  node_t *b = root;

  a = searchR(root, key1);
  b = searchR(root, key2);

  visit_r(root, key1, &d);

  return d;
}

void visit_r(node_t *root, int key, int *d) {
  node_t *a = root;
  node_t *b = root;

  if (root->left == b && root->right == b) {
    return;
  }

  if (a->left == NULL && a->right == NULL) {
  }

  if ((a->left == NULL && a->right != NULL) ||
      (a->right == NULL && a->left != NULL)) {
    if (a->left != NULL) {
      d++;
      visit_r(a->left, key, d);
    } else {
      visit_r(a->right, key, d);
    }
  }

  if (a->left != NULL && a->right != NULL) {
    d++;
    visit_r(a->left, key, d);
    visit_r(a->right, key, d);
  }
  return;
}
