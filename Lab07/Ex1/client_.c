#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Hello World!\n");
  return 0;
}

/** Exercise 01 (A-D) */
/** ----------------- */
/**  */
/** The directory */
/** lab07-BSTLibrary */
/** includes a BST library, i.e. made up of the following files: */
/** * dataInt.c, dataInt.h */
/**   define keys of integer values and all corresponding key-related */
/**   functions. */
/** * dataStr.c, dataStr.h */
/**   define keys of string types and all corresponding key-related */
/**   functions. */
/**   The key field of the BST is an integer value. */
/** * tree.c, tree.h */
/**   contain all BST related functions (readTree, writeTree, insert, */
/**   search, etc.). */
/** * client.c */
/**   includes the main program. */
/**   A while loop allows the user to introduce commands and to run all */
/**   main BST library functions. */
/**  */
/** Enable the version of the library using integer keys. */
/** Verify the library and run it by using the input file */
/** inInt.txt (storing integer values). */
/**  */
/** Afterward, extend the library by writing a new file */
/** treeAddition.c */
/** containing the following described functions. */
/**  */
/** Finally, check those functions by calling them from the main program. */
/** The rest of the library should not be changed (or changed as little as */
/** possible, e.g., additions of prototypes, etc..). */
/**  */
/** Exercise 01-A. */
/** void countNode (node_t *root, int *array); */
/** This function: */
/** - Receives a pointer referencing a root of a tree (root), */
/**   and an array (array) of three integers. */
/**   All array elements are initially equal to zero. */
/** - Stores in the three elements of the array the number of */
/**   nodes with no child, with one single child, and with two children, */
/**   respectively. */
/**  */
/** Exercise 01-B. */
/** void countLevel (node_t * root, int *array, int l); */
/** This function: */
/** - Receives a pointer referencing a root of a tree (root), */
/**   an array of integers (array) whose size is equal to the height of */
/**   the tree, and a recursion level l. */
/**   All array elements are initialized to zero. */
/** - Stores in each element array[i] the total number of */
/**   nodes of the tree at level i. */
/**  */
/** Exercise 01-C. */
/** void countPath (node_t * root, int *np, int *length); */
/** This function: */
/** - Receives a pointer referencing a root of a tree (root). */
/** - Returns in np the number of paths leaving the root and ending */
/**   into a leaf, and the sum of the lengths (number of edges) of all */
/**   those paths. */
/**  */
/** Exercise 01-D. */
/** int visit (node_t *root, int key1, int key2); */
/** This functions: */
/** * Receives a BST root pointer and two integer values */
/**   as parameters */
/** * Evaluates (and prints-out) the distance in the BST of the */
/**   two keys. */
/**   The distance between two keys in a BST is defined as the */
/**   number of edges which it is necessary to traverse to reach */
/**   one key from the other one. */
/**  */
/** Example */
/** ------- */
/** For example, in the following tree, */
/**  */
/**           10 */
/**        /     \ */
/**       5       20 */
/**     /  \     /  \ */
/**    2    8  15   30 */
/**            /     \ */
/**           13     45 */
/**  */
/** the distance between keys 2 and 15 is equal to 4 (edges), and the */
/** distance between keys 45 and 8 is equal to 5 (edges). */
