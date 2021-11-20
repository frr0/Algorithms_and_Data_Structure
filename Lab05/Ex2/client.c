#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void arg(int argc, char **argv);
FILE *open_file(char *filename, char *mode);
void *malloc_ck(int size);
int **scan_mat(int argc, char **argv);
int **find_path(int **m, char *n);
int sum(int **m, int n, int x, int y);

int main(int argc, char **argv) {
  int **m;
  arg(argc, argv);
  int n = atoi(argv[1]);
  m = scan_mat(argc, argv);
  m = find_path(m, argv[1]);

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void arg(int argc, char **argv) {
  assert(argc == 3);
  assert(argv[1] != NULL);
  assert(argv[2] != NULL);
}

FILE *open_file(char *filename, char *mode) {
  FILE *f = fopen(filename, mode);
  assert(f != NULL);
  return f;
}

void *malloc_ck(int size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);
  return ptr;
}

int **scan_mat(int argc, char **argv) {
  FILE *f = open_file(argv[2], "r");
  int n = atoi(argv[1]);
  int **m = malloc_ck(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    m[i] = malloc_ck(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fscanf(f, "%d", &m[i][j]);
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  return m;
}

/** The reflected binary code, also known as Gray code after Frank Gray, */
/** is a binary numeral system where two successive values differ in only */
/** one bit (binary digit).  */
/**  */
/** The code list for n bits can be generated recursively from the list */
/** for n−1 bits by reflecting the list (i.e. listing the entries in */
/** reverse order), concatenating the original list with the reversed */
/** list, prefixing the entries in the original list with a binary 0, and */
/** then prefixing the entries in the reflected list with a binary 1. */
/**  */
/** Example */
/** ------- */
/**  */
/** The two codes of length equal to 1 are made-up of one 0 and one 1: */
/**  */
/**   0 */
/**   1 */
/**  */
/** To move from 1 to 2 bits, the list is firstly reflected (-- indicates */
/** a mirror), and then 0s are added above and 1s below the reflection */
/** point. */
/**  */
/**   0      0     00 */
/**   1      1     01 */
/** ---    ---    --- */
/**          1     11 */
/**          0     10 */
/**  */
/** The process in then repeated to move from 2 to 3 bits (reflection and */
/** then 0s and 1s addition): */
/**  */
/**  00     00    000  */
/**  01     01    001  */
/**  11     11    011  */
/**  10     10    010  */
/** ---    ---    --- */
/**         10    110  */
/**         11    111  */
/**         01    101  */
/**         00    100  */
/**  */
/** Write a recursive program that: */
/** - Receives n as a parameter */
/** - Generates all Gray codes on n bits, and stores the codes in a dynamic */
/**   matrix with n rows and 2^n columns */
/** - Prints out the resulting matrix. */
