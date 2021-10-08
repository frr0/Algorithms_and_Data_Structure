#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

#define MAX 128 
#define UP    1
#define LEFT  2
#define DIAG  3

/* function prototypes */
int lcsLength(char *strX, char *Y, int **b, int **c);
void lcsPrint(char *strX, int **b, int **c, int i, int j);

/*
 *  main program
 */
int main(int argc, char *argv[])
{
  int length, lengthX, lengthY;
  char strX[MAX], strY[MAX];
  int **b, **c;
  FILE *fp;

  /* get strings and allocate the necessary matrices */
  util_check_m(argc>=2, "missing parameter.");
  fp = util_fopen(argv[1], "r");
  fscanf(fp, "%s", strX);
  fscanf(fp, "%s", strY);
  fclose(fp);

  lengthX = strlen(strX)+1;
  lengthY = strlen(strY)+1;
  b = (int **)util_matrix_alloc(lengthX, lengthY, sizeof(int));
  c = (int **)util_matrix_alloc(lengthX, lengthY, sizeof(int));

  /* solve the problem */
  length = lcsLength(strX, strY, b, c);
  printf("LCS length: %d\n", length);
  printf("LCS: ");
  lcsPrint(strX, b, c, lengthX-1, lengthY-1);
  printf("\n");

  /* quit memory */
  util_matrix_dispose((void ***)b, lengthX, lengthY, NULL);
  util_matrix_dispose((void ***)c, lengthX, lengthY, NULL);

  return EXIT_SUCCESS;
}

/* 
 *  build the two tables solving the problem 
 */
int lcsLength(char *strX, char *strY, int **b, int **c)
{
  int m = strlen(strX);
  int n = strlen(strY);
  int i, j;

  /* all elements of the c matrix are initialized with 0s */
  for (i=1; i<=m; i++) {
    for (j=1; j<=n; j++) {
      if (strX[i-1] == strY[j-1]) {
      	c[i][j] = c[i-1][j-1] + 1;
        b[i][j] = DIAG;
      } else {
      	if (c[i-1][j] >= c[i][j-1]) {
          c[i][j] = c[i-1][j];
          b[i][j] = UP;
        } else {
          c[i][j] = c[i][j-1];
          b[i][j] = LEFT;
        }
      }
    }
  }
  return c[m][n];
}

/* 
 *  print the determined LCS
 */
void lcsPrint(char *strX, int **b, int **c, int i, int j)
{
  if (i!=0 && j!=0) {
    if (b[i][j] == DIAG) {
      lcsPrint(strX, b, c, i-1, j-1);
      printf("%c", strX[i-1]);
    } else {
      if (b[i][j] == UP) {
      	lcsPrint(strX, b, c, i-1, j);
      } else {
      	lcsPrint(strX, b, c, i, j-1);
      }
    }
  }
}
