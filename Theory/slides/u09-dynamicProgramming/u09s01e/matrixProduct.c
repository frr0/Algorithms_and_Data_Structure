#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.h"

/* function prototypes */
int *readSizes(char *filename, int *n);
int matrixChainOrder(int *p, int **m, int n);
void matrixChainPrint(int **m, int l, int r);

/*
 *  main program
 */
int main(int argc, char *argv[])
{
  int i, j, n, *p, **m, best;

  /* prepare the needed data structures */
  util_check_m(argc>=2, "missing parameter.");
  p = readSizes(argv[1], &n);
  m = (int **)util_matrix_alloc(n+1, n+1, sizeof(int));
  for (i=0; i<=n; i++) {
    for (j=0; j<=n; j++) {
      m[i][j] = ((i==j) ? 0 : INT_MAX);
    }
  }
   
  /* solve the problem... */
  best = matrixChainOrder(p, m, n);

  /* ... and display the result */
  printf("Minumum cost is = %d\n", best);
  printf("Product to perform is:\n");
  matrixChainPrint(m, 1, n);
  printf("\n");

  /* quit memory */
  util_matrix_dispose((void ***)m, n+1, n+1, NULL);
  free(p);
  return EXIT_SUCCESS;
}

/*
 *  load the matrices' sizes from the input file
 */
int *readSizes(char *filename, int *num)
{
  int i, n, *p;
  FILE *fp;

  fp = util_fopen(filename, "r");
  fscanf(fp, "%d", &n);
  p = (int *)util_malloc((n+1)*sizeof(int));
  for (i=0; i<n; i++) {
    fscanf(fp, "%dx%d", &p[i], &p[i+1]);
  }
  fclose(fp);
  *num = n;
  return p;
}

/*
 *  find the optimal order for multiplying the matrices
 */
int matrixChainOrder(int *p, int **m, int n)
{
  int i, j, k, l, cost;

  for (l=2; l<=n; l++) {
    for (i=1; i<=n-l+1; i++) {
      j = i+l-1;
      for (k=i; k<=j-1; k++) {
        cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if (cost < m[i][j]) {
          m[i][j] = cost;
          m[j][i] = k;
        }
      }
    }
  }

  return m[1][n];
}

/*
 *  show the optimal order for multiplying the matrices
 */
void matrixChainPrint(int **m, int i, int j)
{
  int k;

  if (i == j) {
    printf("A%d", i);
    return;
  }
   
  k = m[j][i];
  printf("(");
  matrixChainPrint(m, i, k);
  printf(" * ");
  matrixChainPrint(m, k+1, j);
  printf(")");   
}
