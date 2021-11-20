#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void arg(int argc, char **argv);
FILE *open_file(char *filename, char *mode);
void *malloc_ck(int size);
/** int **scan_mat(int argc, char **argv); */
int *find_path(int *m, char *n);
int sum(int *val, int *sol, int *mark, int n, int count, int pos);

int main(int argc, char **argv) {
  int *m;
  arg(argc, argv);
  int n = atoi(argv[1]);
  /** m = scan_mat(argc, argv); */
  m = find_path(m, argv[1]);

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", m[i]);
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

/** int **scan_mat(int argc, char **argv) { */
/**   FILE *f = open_file(argv[2], "r"); */
/**   int n = atoi(argv[1]); */
/**   int **m = malloc_ck(n * sizeof(int *)); */
/**  */
/**   for (int i = 0; i < n; i++) { */
/**     m[i] = malloc_ck(n * sizeof(int)); */
/**   } */
/**  */
/**   for (int i = 0; i < n; i++) { */
/**     for (int j = 0; j < n; j++) { */
/**       fscanf(f, "%d", &m[i][j]); */
/**       printf("%d ", m[i][j]); */
/**     } */
/**     printf("\n"); */
/**   } */
/**  */
/**   return m; */
/** } */

int *find_path(int *m, char *n) {
  int n1 = 0, k = 0, count = 0, pos = 0;
  int nn = atoi(n);
  int s = (nn * nn);
  int val[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *sol = malloc_ck((nn * nn) * sizeof(int));
  int mark[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  if (!sum(val, sol, mark, s, count, pos)) {
    return sol;
  }
  return sol;
}

int sum(int *val, int *sol, int *mark, int n, int count, int pos) {
  int r1, c1, r3, c3, r2, c2, d1, d2, i;

  if (pos >= n) {
    for (int i = 0, a = 0; i < n / 3; i++, a = a + 3) {
      r1 += sol[i];
      r2 += sol[i + 2];
      r3 += sol[i + 1];
      c1 += sol[a];
      c2 += sol[a + 1];
      c3 += sol[a + 2];
      /** d1 += sol[i]; */
      /** d2 += sol[n - (i)]; */
      if (c1 == r1 && c2 == r2 && c3 == r3 && c1 == c2 && c3 == c2 /** && */
          /**  r1 == d1 && r2 == d2 */) {
        return 1;
        return count + 1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (mark[i] == 0) {
      mark[i] = 1;
      sol[pos] = val[i];
      count = sum(val, sol, mark, n, count, pos + 1);
      mark[i] = 0;
    }
  }
  return count;
}

/** Write a C program solving the "magic square" problem. */
/**  */
/** A "magic square" of size equal to n is a (n x n) matrix of */
/** integers containing only integer numbers from 1 to (n x n), */
/** such that the sum of those values on all rows, on all columns, */
/** and on the two diagonals is the same. */
/**  */
/** The program has to receive two parameters on the command line: */
/** * an integer value n */
/** * a file name */
/** and it has to store one magic square of size n on the file. */
/**  */
/** Example */
/** ------- */
/**  */
/** If we suppose to run the program with the following two parameters */
/** 3 square.txt */
/** it has to store in the file the following matrix: */
/**  */
/** 8 3 4 */
/** 1 5 9 */
/** 6 7 2 */
/**  */
/** which includes all numbers from 1 to 9 (3x3) and satisfies the requested
 */
/** criteria (all the above mentioned sums are equal to 15). */
