#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100+1

void check_args(int argc, char *argv[]);
char **scan_file(int args, char *argv[], int *n_lines, FILE **f2);
FILE *open_file(char *filename, char *mode);
char **order(char **mat, int nlines);

int main(int argc, char *argv[]) {
  int nlines;
  FILE *f2;
  char **mat;

  check_args(argc, argv);
  mat = scan_file(argc, argv, &nlines, &f2);
  for (int i=0; i<nlines; i++){
    printf("%s\n", mat[i]);
  }
  mat = order(mat, nlines);
  printf("\n");
  for (int i=0; i<nlines; i++){
    printf("%s\n", mat[i]);
    fprintf(f2, "%s\n", mat[i]);
  }
  return 0;
}

void check_args(int argc, char *argv[]){
  if (argc != 3) {
    printf("Error, not 3 args");
    exit(-1);
  }
}

char **scan_file(int args, char *argv[], int *n_lines, FILE **f2){
  FILE *f1;
  *n_lines = 0;
  char **mat;

  f1 = open_file(argv[1], "r");
  *f2 = open_file(argv[2], "w");
  fscanf(f1, "%d", n_lines);
  printf("%d\n", *n_lines);

  mat = malloc(*n_lines * sizeof(char*));
  for (int i=0; i<*n_lines; i++){
    mat[i] = malloc(C * sizeof(char));
  }

  for (int i=0; i<*n_lines; i++){
    fscanf(f1, "%s", mat[i]);
    /** printf("%s\n", mat[i]); */
  }
  return mat;
}

FILE *open_file(char *filename, char *mode){
  FILE *f = fopen(filename, mode);
  if (f == NULL){
    perror("Error open file");
    exit(-2);
  }
  return f;
}

char **order(char **mat, int nlines){
  char temp[C];

  for (int i=0; i<nlines-1; i++) {
    for (int j=0; j<nlines-i-1; j++) {
      if (strcmp(mat[j], mat[j+1]) > 0) {
        strcpy(temp, mat[j]);
        strcpy(mat[j], mat[j+1]);
        strcpy(mat[j+1], temp);
      }
    }
  }
  for (int i=0; i<nlines; i++){
    /** printf("%s\n", mat[i]); */
  }
  return mat;
}
