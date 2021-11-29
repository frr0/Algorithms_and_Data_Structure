#include "treePrivate.h"
#include <stdio.h>

void countNode(node_t *root, int *array) {

  while (root != NULL) {
    if (root->left == NULL && root->right == NULL) {
      array[0]++;
      /** return; */
    }

    if ((root->left == NULL && root->right != NULL) ||
        (root->right == NULL && root->left != NULL)) {
      array[1]++;
      if (root->left != NULL) {
        return countNode(root->left, array);
      } else
        return countNode(root->right, array);
    }

    if (root->left != NULL && root->right != NULL) {
      array[2]++;
    }
    return countNode(root->left, array);
    return countNode(root->right, array);
  }
  printf("Node with no children: %d\n", array[0]);
  printf("Node with 1 child: %d\n", array[1]);
  printf("Node with 2 children: %d\n", array[2]);
}

void countLevel(node_t *root, int *array, int l) {
  while (root != NULL) {
    if (root->left == NULL && root->right == NULL) {
      array[0]++;
    }

    if ((root->left == NULL && root->right != NULL) ||
        (root->right == NULL && root->left != NULL)) {
      array[1]++;
      if (root->left != NULL) {
        return countLevel(root->left, array, l);
      } else
        return countLevel(root->right, array, l);
    }

    if (root->left != NULL && root->right != NULL) {
      array[2]++;
    }
    return countLevel(root->left, array, l);
    return countLevel(root->right, array, l);
  }
}

void countPath(node_t *root, int *np, int *length) {}
int visit(node_t *root, int key1, int key2) { return 0; }
