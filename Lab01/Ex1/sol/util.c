#include "util.h"
#include "client.h"
#include <stdio.h>
#include <string.h>

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
  /** char *word; */

  /** __word = malloc_ck(II * sizeof(char)); */
  f = open_file(filename, "r");
  fo = open_file("f1.txt", "r");
  line = malloc_ck(C * sizeof(char));
  /** word = malloc_ck(C * sizeof(char)); */

  for (int i=0; i<3; i++){
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
    for(int i=0; i<3; i++){
      if((strstr(line, name[i].word)) != NULL) {
        name[i].occurrences++;
      }
    }
   }
  for (int k=0; k<3; k++){
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

/** Algorithms and Data Structures */
/** Laboratory number 00 */
/** -------------------- */
/**  */
/**  */
/**  */
/** Exercise 01 */
/** ----------- */
/**  */
/** A first file stores a text with an undefined number of rows. */
/** Each row is shorter than 100 characters. */
/** A second file stores a list of words. */
/** Each word is shorter than 20 characters, and the number of words */
/** is at most equal to 100. */
/**  */
/** Write a program that counts the number of times each word stored in the */
/** second file appears in the text stored in the first file. */
/**  */
/** Once the file has been read, the program has to print out (on standard */
/** output) each word with its absolute frequency, i.e., the number of */
/** times it appears in the text. */
/**  */
/** Both files have to be read just once. */
/** Capital and small letters have to be considered as equivalent, e.g., */
/** "word" and "WORD" and "WoRd" are considered as equivalent. */
/**  */
/** Example */
/** ------- */
/**  */
/** Let the first file be the following one: */
/**  */
/** Watch your thoughts ; they become words . */
/** Watch your words ; they become actions . */
/** Watch your actions ; they become habits . */
/** Watch your habits ; they become character . */
/** Watch your character ; it becomes your destiny . */
/** Lao-Tze */
/**  */
/** and the second file the following one: */
/**  */
/** watch */
/** words */
/** become */
/**  */
/** The program has to print-out: */
/**  */
/** watch - 5 occurrence(s) */
/** words - 2 occurrence(s) */
/** become - 4 occurrence(s) */
/**  */
/**  */
/**  */
/** Exercise 02 */
/** ----------- */
/**  */
/** A file defines a set of rectangles with the following format: */
/** * Each row of the file contains 1 string and 2 real numbers: */
/**   - The string (4 character long) is the rectangle identifier, */
/**   - The two numbers specifies the x and y coordinates, */
/**     respectively, of one of its vertices */
/** * For each rectangle there are two lines in the file, specifying */
/**   the coordinate of two opposite vertices (top-right and */
/**   bottom-left or top-left and bottom-right). */
/**   Notice that, in general, the two rows defining a rectangle are */
/**   not consecutive, and that it is not known which vertex they */
/**   specify. */
/** In any case, suppose the maximum number of rectangles is 100. */
/**  */
/** Write a C program that receives 3 file names on the command line: */
/** - The first file is an input file, and it contains all rectangles */
/**   specifications as previously indicated */
/** - The second file is an output file, and it must contain the */
/**   name of the rectangles ordered by ascending area values. */
/** - The third file is an output file, and it must contain the */
/**   name of the rectangles ordered by ascending perimeter values. */
/**  */
/** Suggestion */
/** ---------- */
/**  */
/** Use an array of structures where each element on the array stores */
/** the name and the two extreme coordinates. */
/**  */
/** Example */
/** ------- */
/**  */
/** Let us suppose that the program receives the following three parameters: */
/** fileIn.txt fileArea.txt filePerimeter.txt */
/**  */
/** Moreover, let us suppose that the content of fileIn.txt is the following: */
/**  */
/** rct2  1.5 3.5 */
/** xxyy  -0.5 3.0 */
/** xxyy  1.5 2.0 */
/** abcd  1.0 4.5 */
/** ktkr  -2.5 1.5 */
/** abcd  2.0 2.0 */
/** rct2  3.5 -2.0 */
/** trya  2.5 -1.0 */
/** ktkr  1.5 3.5 */
/** trya  4.0 4.0 */
/**  */
/** As areas and perimeters of the rectangles are: */
/** rct2   area=11.00   perimeter=15.00 */
/** xxyy   area= 2.00   perimeter= 6.00 */
/** abcd   area= 2.50   perimeter= 7.00 */
/** ktkr   area= 8.00   perimeter=12.00 */
/** trya   area= 7.50   perimeter=13.00 */
/** the program has to generate the following two files: */
/**  */
/** fileArea.txt: */
/** rct2 */
/** ktkr */
/** trya */
/** abcd */
/** xxyy */
/**  */
/** filePerimeter.txt: */
/** rct2 */
/** trya */
/** ktkr */
/** abcd */
/** xxyy */
