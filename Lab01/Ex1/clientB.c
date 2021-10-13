/** #include "client.h" */
/** #include "util.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define C 100+1
#define T 3
#define II 20+1
#define DEBUG 0

// typedef struct name_s *name_t;

typedef struct name_s{
  /** char word[II]; */
  char *word;
  int occurrences;
}name_t;


void arg_check(int argc, char *argv[]);
FILE *open_file(char* filename, char* mode);
void read_words(char *filename, char *mode, int N);
void Search_words(char *filename, char *mode, int N);
void *malloc_ck(int size);
char **mat_allocation(int c, int r);
char **mat_allocation(int c, int r);

int main(int argc, char *argv[]) {
  int n1 = 0;
  int n2= 0;

  
  arg_check(argc, argv);
  /** open_file(argv[2], "r"); */
  read_words(argv[2], "r", n2);
  /** open_file(argv[1], "r"); */
  Search_words(argv[1], "r", n1);
  return 0;
} 

void arg_check(int argc, char *argv[]) {
  if (argc != 3) // checking argc
  {
    printf("Error, not 3 args");
    exit(-1);
  }
}

FILE *open_file(char *filename, char *mode) {
  FILE *f;
  f = fopen(filename, mode);
  if (!f) {
    perror(filename);
    exit(EXIT_FAILURE);
  }

  return f;
}

void read_words(char *filename, char *mode, int N) {
  name_t name[T];
  FILE *f;
  FILE *fo;
  char __word[II];
  char *line;
  int nn = 0;
  /** char *word; */

  /** __word = malloc_ck(II * sizeof(char)); */
  f = open_file(filename, "r");
  fo = open_file("f1.txt", "r");
  line = malloc_ck(C * sizeof(char));
  /** word = malloc_ck(C * sizeof(char)); */

  fscanf(f, "%d", &nn);
  for(int i = 0; i<nn; i++){
    name[i].word = malloc(II * sizeof(char));
  }

  for (int i=0; i<nn; i++){
    fscanf(f, "%s", __word);
    /** printf("upper: %s\n", __word); */
    for(int j = 0; __word[j]; j++){
      __word[j] = tolower(__word[j]);
    }
    /** printf("in __word: %s\n", __word); */
    strcpy(name[i].word, __word);
    /** printf("nella struct: %s\n", name[i].word); */
  }

  while(fgets(line, C, f) != NULL) {
    for(int i = 0; line[i]; i++){
      line[i] = tolower(line[i]);
    }
    for(int i=0; i<nn; i++){
      if((strstr(line, name[i].word)) != NULL) {
        name[i].occurrences++;
      }
    }
   }
  for (int k=0; k<nn; k++){
    /** printf("%s: occurs %d times\n", name[k].word, name[k].occurrences); */
  }


  fclose(f);
}

void Search_words(char *filename, char *mode, int N) {
  name_t name[T];
  char *line;
  char *word;
  char *string;
  FILE *f;
  int i = 0;

  line = malloc_ck(C * sizeof(char));
  word = malloc_ck(C * sizeof(char));
  string = malloc_ck(C * sizeof(char));
  f = open_file(filename, "r");

  for (int k=0; k<3; k++){
    name[i].occurrences = 0;
  }

  while(fgets(line, C, f) != NULL) {
    for(int i=0; i<3; i++){
      for(int i = 0; line[i]; i++){
        line[i] = tolower(line[i]);
      }
      if((strstr(line, name[i].word)) != NULL) {
        name[i].occurrences++;
      }
    }
   }

  printf("\n");
  for (int k=0; k<3; k++){
    printf("%s: occurs %d times\n", name[k].word, name[k].occurrences);
  }

  fclose(f);

  return;
}

void *malloc_ck(int size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

char **mat_allocation(int c, int r) {
  char **mat;
  c = 20 + 1;
  r = 100 + 1;
  /** allocation rows */
  mat = malloc_ck(r * sizeof(char *));

  /** allocation colons (lettes/characters) */
  for (int i = 0; i < c; i++) {
    mat[i] = malloc_ck(c * sizeof(char));
  }

  return mat;
}
