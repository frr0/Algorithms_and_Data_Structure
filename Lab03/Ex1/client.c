#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define M 1000+1

typedef struct list_s list_t;

struct list_s {
  char *word;
  int occurrence;
  list_t *next;
};

void args_check(int argc, char *argv[]);
list_t *scan_file(int argc, char *argv[]);
FILE *file_open(char *filename, char *mode);

int main(int argc, char *argv[]) {
  list_t *w;

  args_check(argc, argv);
  w = scan_file(argc, argv);
  

  return 0;
}

void args_check(int argc, char *argv[]){
  if (argc != 3){
    perror("args error, not 3");
    exit(-1);
  }
}

list_t *scan_file(int argc, char *argv[]){
  list_t *ww;
  int n = 0;
  char *str;
  char *word;
  FILE *f1 = file_open(argv[1], "r");
  FILE *f2 = file_open(argv[2], "w");

  str = malloc(M * sizeof(char));
  word = malloc(M * sizeof(char));
  if (str == NULL){
    perror("error allocation");
    exit(-3);
  }

  while (fgets(str, M, f1) != NULL){
    while(sscanf(str, "%s ", word) != EOF){
      for (int i=0; i<20; i++){
        word[i] = tolower(word[i]);
      }
        printf("%s\n", word);
    }
    n++;
  }
  fclose(f1);
  printf("%d\n", n);
  f1 = file_open(argv[1], "r");



  return ww;
}

FILE *file_open(char *filename, char *mode){
  FILE *f = fopen(filename, mode);
  if (f == NULL){
    perror("error file open");
    exit(-2);
  }
  return f;
}

/** Algorithms and Programming */
/** Laboratory number 06 */
/** -------------------- */
/**  */
/**  */
/**  */
/** Exercise 01 (A, B, C) */
/** Extension of Exercise 01, Laboratory 03 */
/** --------------------------------------- */
/**  */
/** A text of unknown length, but whose rows are limited to 1000 */
/** characters, is stored in a file. */
/**  */
/** Write a C application able to evaluate the absolute frequency of all */
/** strings which appear in the file. */
/**  */
/** More specifically the program has to: */
/** * Receive on the command line two file names (the input and the output */
/**   file, respectively). */
/** * Read the input file and store all words in a list. */
/**   Each node of the list must contain the string and its absolute */
/**   frequency within the input file. */
/**   Capital and small letters have to be considered as equivalent */
/**   (i.e., "WORD", "Word", and "word" are the same string). */
/** * Store the list into the output file. */
/**  */
/** The list may be manipulated using: */
/** 1. Head insertions. */
/**    In this way the string order within the file will be inverted into */
/**    the list. */
/** 2. Tail insertions (using a list with a tail pointer with or without a */
/**    circular implementation). */
/**    In this way the string order within the file will be maintained into */
/**    the list. */
/** 3. Ordered insertion (into an ordered list). */
/**    In this way the string order within the file will be reorder into */
/**    the list in alphabetic order. */
/** At choice implement version A, B, or C or all of them. */
/**  */
/** Example */
/** ------- */
/**  */
/** This is a correct input file */
/**  */
/** Mi illumino di immenso */
/** Illumino di immenso */
/** Di immenso */
/** IMMENSO */
/**  */
/** The output file has to be the following (order depends on the type of */
/** the list selected): */
/**  */
/** immenso 4 */
/** di 3 */
/** illumino 2 */
/** Mi 1 */
