#include "mat.h"

char **scanmat(int argc, char **argv) {
  FILE *f = open_file(argv[1], "r");
  int r, c;
  char **m;

  check_args(argc, argv);

  fscanf(f, "%d %d\n", &r, &c);

  m = malloc2d_ck((r) * sizeof(char *), (c + 1) * sizeof(char));

  /** ========================================== */
  /** LOAD ORIGINAL MAP */
  printf("\n================ MAP 1 =================\n");
  printf("\nORIGINAL");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < (c + 1); j++) {
      fscanf(f, "%c", &m[i][j]);
    }
  }
  /** PRINT ORIGINAL MAP */
  printmat(m, argc, argv);

  /** ESCAPE 1 */
  if (escape1(m, 2, 6)) {
    /** PRINT ESCAPED MAP 1*/
    printmat(m, argc, argv);
  }
  /** ========================================== */
  f = open_file(argv[1], "r");
  fscanf(f, "%d %d\n", &r, &c);
  /** RELOAD ORIGINAL MAP */
  printf("\n================ MAP 2 =================\n");
  printf("\nORIGINAL");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < (c + 1); j++) {
      fscanf(f, "%c", &m[i][j]);
    }
  }
  /** PRINT ORIGINAL MAP */
  printmat(m, argc, argv);

  /** ESCAPE 2 */
  if (escape2(m, 2, 6)) {
    /** PRINT ESCAPED MAP 2*/
    printmat(m, argc, argv);
  }
  /** ========================================== */
  f = open_file(argv[1], "r");
  fscanf(f, "%d %d\n", &r, &c);
  /** RELOAD ORIGINAL MAP */
  printf("\n================ MAP 3 =================\n");
  printf("\nORIGINAL");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < (c + 1); j++) {
      fscanf(f, "%c", &m[i][j]);
    }
  }
  /** PRINT ORIGINAL MAP */
  printmat(m, argc, argv);
  /** ESCAPE 3 */
  if (escape3(m, 2, 6)) {
    /** PRINT ESCAPED MAP 3*/
    printmat(m, argc, argv);
  }
  /** ========================================== */

  return m;
}

void printmat(char **m, int argc, char **argv) {
  int r, c;
  dim(&r, &c, argc, argv);
  printf("\n");
  printf("\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < (c + 1); j++) {
      printf("%c", m[i][j]);
    }
  }
}

void dim(int *r, int *c, int argc, char **argv) {
  FILE *f = open_file(argv[1], "r");
  fscanf(f, "%d %d", r, c);
  fclose(f);
}
