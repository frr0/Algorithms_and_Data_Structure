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
list_t *scan_file(list_t *head, int argc, char *argv[]);
list_t *insert (list_t *head, char *word); 
FILE *file_open(char *filename, char *mode);
void display (list_t *head);

int main(int argc, char *argv[]) {
  list_t *w = NULL;

  args_check(argc, argv);
  w = scan_file(w, argc, argv);
  
  for (list_t *tmp = w; tmp != NULL; tmp = tmp->next){
    /** printf("%s\n%d\n", w->word, w->occurrence); */
  }

  return 0;
}

void args_check(int argc, char *argv[]){
  if (argc != 3){
    perror("args error, not 3");
    exit(-1);
  }
}

list_t *scan_file(list_t *head, int argc, char *argv[]){
  list_t *ww = NULL;
  list_t *tmp;
  int n = 0;
  int m = 0;
  int i = 0;
  int found = 0;
  char *str;
  char *word;
  FILE *f1 = file_open(argv[1], "r");

  str = malloc(M * sizeof(char));
  word = malloc(M * sizeof(char));
  if (str == NULL){
    perror("error allocation");
    exit(-3);
  }

  while (fgets(str, M, f1) != NULL){
    while(sscanf(str, "%s", word) > 0){
      for (i=0; i<strlen(word); i++){
        word[i] = tolower(word[i]);
      }
      str = str + strlen(word) + 1;

      if (m == 0){
        ww = insert(ww, word);
        m++;
      }
      if (m != 0){
        tmp = ww;
        found = 0;
        while (tmp != NULL && found == 0) {
          if(strcmp(tmp->word, word) == 0){
            found = 1;
            tmp->occurrence++;
            /** printf("word: %s\n", tmp->word); */
            /** printf("occurrence: %d\n", tmp->occurrence); */
          }else if (strcmp(tmp->word, word) != 0){
            found = 0;
          }
            tmp = tmp->next;
        }
          if (found == 0){
           ww = insert(ww, word);
           m++;
          }
      }

    }
    n++;
  }
  while (tmp != NULL) {
            printf("word: %s\n", ww->word);
            printf("occurrence: %d\n", ww->occurrence);
    /** printf("%s\n", ww->word); */
    /** printf("%d\n", ww->occurrence); */
    ww = ww->next;
  }
  /** for (list_t *tmp = ww; tmp != NULL; tmp = tmp->next){ */
  /**   printf("%s\n%d\n", ww->word, ww->occurrence); */
  /** } */
  fclose(f1);
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

list_t *insert (list_t *head, char *word) {   
  list_t *p;   
   
  p = (list_t *)malloc(sizeof(list_t));   
  p->word = strdup(word);
  p->occurrence = 1;   
  p->next = NULL;

  p->next = head;   
  head = p;   

  return p;
}

void display (list_t *head) {
  int i=0;

  while (head != NULL) {
    /** printf("%s\n", head->word); */
    /** printf("%d\n", head->occurrence); */
    /** head = head->next; */
  }
}
