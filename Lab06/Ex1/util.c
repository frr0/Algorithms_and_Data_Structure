#include "util.h"

void check_args(int argc, char **argv) { assert(argc == 2); }

FILE *open_file(char *filename, char *mode) {
  FILE *f = fopen(filename, mode);
  assert(f != NULL);
  return f;
}

char *malloc1d_ck(int r) {
  char *ptr = malloc(r);
  assert(ptr != NULL);
  return ptr;
}

char **malloc2d_ck(int r, int c) {
  char **ptr = malloc(r);
  assert(ptr != NULL);
  for (int i = 0; i < r; i++) {
    ptr[i] = malloc1d_ck(c * sizeof(char));
    assert(ptr != NULL);
  }
  return ptr;
}
