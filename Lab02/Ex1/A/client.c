#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100+1

struct string {
  char *str;
};

void check_args(int argc, char *argv[]);
struct string *scan_file(int args, char *argv[], int *n_lines, FILE **f2);
FILE *open_file(char *filename, char *mode);
void order(struct string *w, int nlines);

int main(int argc, char *argv[]) {
  struct string *wrd;
  int nlines;
  FILE *f2;

  check_args(argc, argv);
  wrd = scan_file(argc, argv, &nlines, &f2);
  for (int i=0; i<nlines; i++){
    printf("%s\n", wrd[i].str);
  }
  order(wrd, nlines);
  printf("\n");
  for (int i=0; i<nlines; i++){
    printf("%s\n", wrd[i].str);
    fprintf(f2, "%s\n", wrd[i].str);
  }
  return 0;
}

void check_args(int argc, char *argv[]){
  if (argc != 3) {
    printf("Error, not 3 args");
    exit(-1);
  }
}

struct string *scan_file(int args, char *argv[], int *n_lines, FILE **f2){
  FILE *f1;
  *n_lines = 0;

  f1 = open_file(argv[1], "r");
  *f2 = open_file(argv[2], "w");
  fscanf(f1, "%d", n_lines);
  printf("%d\n", *n_lines);

  struct string *word;
    word = malloc(*n_lines * sizeof(struct string));

  for (int i=0; i<*n_lines; i++){
    word[i].str = malloc(C * sizeof(char));
    fscanf(f1, "%s", word[i].str);
    /** printf("%s\n", word[i].str); */
  }
  return word;
}

FILE *open_file(char *filename, char *mode){
  FILE *f = fopen(filename, mode);
  if (f == NULL){
    perror("Error open file");
    exit(-2);
  }
  return f;
}

void order(struct string *w, int nlines){
  char temp[C];

  for (int i=0; i<nlines-1; i++) {
    for (int j=0; j<nlines-i-1; j++) {
      if (strcmp(w[j].str, w[j+1].str) > 0) {
        strcpy(temp, w[j].str);
        strcpy(w[j].str, w[j+1].str);
        strcpy(w[j+1].str, temp);
      }
    }
  }
  for (int i=0; i<nlines; i++){
    /** printf("%s\n", w[i].str); */
  }
}
