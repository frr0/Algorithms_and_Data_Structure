#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEBUG 0
#define C 100+1
#define T 3
#define II 20+1

// typedef struct name_s *name_t;

typedef struct {
  char word[II];
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
  int n2 = 0;
  /** int n3 =0; */
  
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
  char __word[II];

  /** __word = malloc_ck(II * sizeof(char)); */
  f = open_file(filename, "r");

  for (int i=0; i<3; i++){
    fscanf(f, "%s", __word);
    /** printf("upper: %s\n", __word); */
    for(int j = 0; __word[j]; j++){
      __word[j] = tolower(__word[j]);
    }
    /** printf("in __word: %s\n", __word); */
    strcpy(name[i].word, __word);
    printf("nella struct: %s\n", name[i].word);
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

  while (fgets(line, C, f) != NULL) {
    string = line;
    while (sscanf(string, "%s", word) > 0) {
      for (i = 0; i < 3; i++) {
        if (strcmp(word, name[i].word) == 0) {
          name[i].occurrences++;
        }
      }
      string = string + strlen(word);
    }
  }

  for (int k=0; k<3; k++){
    printf("%s: occurs %d times\n", name[i].word, name[i].occurrences);
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
