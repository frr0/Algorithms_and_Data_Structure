#include "treeAddition.h"
#include "treePublic.h"
#include <stdio.h>

#define OK 1
#define KO 0

int main(void) {
  node_t *root, *tmp;
  data_t d;
  int retValue, end = 0, l = 0, length = 0;
  int array1[3] = {0, 0, 0};
  int array2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int np = 0, key1 = 8, key2 = 15;
  char row[MAXC];
  FILE *fp = NULL;

  root = NULL;
  root = createEmptyTree();

  while (!end) {

    fprintf(stdout, "User selection\n");
    fprintf(stdout, "\t1) Insert one single node\n\t2) Cancel one single "
                    "node\n\t3) Search a node\n");
    fprintf(stdout, "\t4) Print BST on stdout"
                    "\n\t5) Count node"
                    "\n\t6) Count level"
                    "\n\t7) Count path"
                    "\n\t8) Visit"
                    "\n\t9) Write BST on file\n\t11) "
                    "Read BST from file\n");
    fprintf(stdout, "\t12) Compute min and max\n\t0) End\n\t> ");
    scanf("%1s", row);

    switch (atoi(row)) {

    case 11:
      fprintf(stdout, "data: ");
      retValue = readData(stdin, &d);
      if (retValue == 0) {
        fprintf(stderr, "Input erro.\n");
        exit(0);
      }
      root = insert(root, d);
      break;

    case 2:
      fprintf(stdout, "data: ");
      retValue = readData(stdin, &d);
      if (retValue == 0) {
        fprintf(stderr, "Input erro.\n");
        exit(0);
      }
      root = delete (root, d);
      break;

    case 3:
      fprintf(stdout, "data: ");
      retValue = readData(stdin, &d);
      if (retValue == 0) {
        fprintf(stderr, "Input error.\n");
        exit(0);
      }

      tmp = searchI(root, d);
      if (tmp != NULL) {
        fprintf(stdout, "Iterative Search: Found -> ");
        writeData(stdout, getData(tmp));
      } else {
        fprintf(stdout, "Iterative Search: Not Found\n");
      }
      tmp = searchR(root, d);
      if (tmp != NULL) {
        fprintf(stdout, "Recursive Search: Found -> ");
        writeData(stdout, getData(tmp));
      } else {
        fprintf(stdout, "Recursive Search: Not Found\n");
      }
      break;

    case 4:
      writeTree(stdout, root, INORDER);
      break;

    case 5:
      writeTree(stdout, root, PREORDER);
      countNode(root, array1);
      /** printf("length: %d\n", l); */
      printf("Node with no children: %d\n", array1[0]);
      printf("Node with 1 child: %d\n", array1[1]);
      printf("Node with 2 children: %d\n", array1[2]);
      break;

    case 6:
      countLevel(root, array2, l);
      for (int i = 0; i < 10; i++) {
        if (array2[i] != 0) {
          printf("# of elements al level %d: %d\n", i, array2[i]);
        }
      }
      break;

    case 7:
      countPath(root, &np, &length);
      printf("# of path: %d\n", np);
      printf("sum of path: %d\n", length);
      break;

    case 8:
      visit(root, key1, key2);
      break;

    case 9:
      fprintf(stdout, "File Name: ");
      scanf("%s", row);

      if (strcmp(row, "stdout") == 0) {
        fp = stdout;
      } else {
        fp = fopen(row, "w");
      }

      if (fp == NULL) {
        fprintf(stderr, "Error Opening File %s\n", row);
        break;
      }

      writeTree(fp, root, PREORDER);

      if (strcmp(row, "stdout") != 0) {
        fclose(fp);
      }
      break;

    case 1:
      /** fprintf(stdout, "File Name: "); */
      /** scanf("%s", row); */

      fp = fopen("inInt.txt", "r");
      if (fp == NULL) {
        fprintf(stderr, "Error Opening File %s\n", row);
      } else {
        freeTree(root);
        root = readTree(fp);
      }
      break;

    case 12:
      fprintf(stdout, "Tree minimum iterative: ");
      tmp = treeMinI(root);
      writeData(stdout, getData(tmp));
      fprintf(stdout, "Tree minimum recursive: ");
      tmp = treeMinR(root);
      writeData(stdout, getData(tmp));
      fprintf(stdout, "Tree maximum iterative: ");
      tmp = treeMaxI(root);
      writeData(stdout, getData(tmp));
      fprintf(stdout, "Tree maximum recursive: ");
      tmp = treeMaxR(root);
      writeData(stdout, getData(tmp));
      break;

    case 0:
      end = 1;
      break;

    default:
      fprintf(stderr, "Unknown Option.\n");
      break;
    }
  }

  freeTree(root);

  return (OK);
}
