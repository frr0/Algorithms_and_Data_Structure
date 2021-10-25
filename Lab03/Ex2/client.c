#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 50+1

int t = 0;

typedef struct employee_s employee_t;

struct employee_s {
  char *name;
  char *id;
  int d;
  int m;
  int y;
  int salary;
  employee_t *next;
  employee_t *prev;
};

void args_check(int argc, char *argv[]);
int file_num_of_line_completed(char *filename, char *mode, int N);
employee_t *scan_file(employee_t *head, int argc, char *argv[]);
employee_t *insert (employee_t *head, char *name, char *id, int dd, int mm, int yy, int salary); 
FILE *file_open(char *filename, char *mode);
void display (employee_t *head);
void print (employee_t *head, int argc, char *argv[]);

int main(int argc, char *argv[]) {
  employee_t *e = NULL;

  args_check(argc, argv);
  e = scan_file(e, argc, argv);
  print(e, argc, argv);
  

  return 0;
}

void args_check(int argc, char *argv[]){
  if (argc != 4){
    perror("args error, not 3");
    exit(-1);
  }
}

employee_t *scan_file(employee_t *head, int argc, char *argv[]){
  employee_t *ee = NULL;
  char *name;
  char *id;
  int dd;
  int mm;
  int yy;
  int salary;
  int n = 0;
  char *str;
  n = file_num_of_line_completed(argv[1], "r", n);

  str = malloc(10*L * sizeof(char));
  if (str == NULL){
    perror("error allocation");
    exit(-3);
  }
  name = malloc(L * sizeof(char));
  if (name == NULL){
    perror("error allocation");
    exit(-3);
  }
  id = malloc(L * sizeof(char));
  if (id == NULL){
    perror("error allocation");
    exit(-3);
  }

  /** printf("%d\n", n); */
  FILE *f1 = file_open(argv[1], "r");
  for (int i=0; i<n; i++){
    fscanf(f1, "%s %s %d.%d.%d %d", name, id, &dd, &mm, &yy, &salary);
    ee = insert(ee, name, id, dd, mm, yy, salary);
  }
  display (ee);
  fclose(f1);
  return ee;
}

FILE *file_open(char *filename, char *mode){
  FILE *f = fopen(filename, mode);
  if (f == NULL){
    perror("error file open");
    exit(-2);
  }
  return f;
}

int file_num_of_line_completed(char *filename, char *mode, int N) {
  char *line;
  FILE *f;
  int n=0;

  line = malloc(4*L*sizeof(char));
  f = file_open(filename, mode);

  while(fgets(line, 4*L, f) != NULL) {
    n++;
  }

  fprintf(stdout,"\nNumber of lines: %d\n", n);
  fclose(f);
  return n;
}


employee_t *insert (employee_t *head, char *name, char *id, int dd, int mm, int yy, int salary) {   
  employee_t *p;   
   
  p = (employee_t *)malloc(sizeof(employee_t));   
  p->name = strdup(name);
  p->id = strdup(id);   
  p->d = dd;
  p->m = mm;
  p->y = yy;
  p->salary = salary;

  p->next = head;   
  head = p;
  if (t) { head->next->prev = head; } t++;

  return p;
}

void display (employee_t *head) {

  printf("\n");
  printf("head->name (first in list): %s\n",
    head->name);
  printf("head->next->name (second in list): %s\n",
    head->next->name);
  printf("head->next->next->name (third in list): %s\n",
    head->next->next->name);
  printf("head->next->next->next->name (fourth in list): %s\n",
    head->next->next->next->name);
  printf("\n");
  printf("head->next->next->next->name (fourth in list): %s\n",
    head->next->next->next->name);
  printf("head->next->next->next->prev->name (third in list): %s\n",
    head->next->next->next->prev->name);
  printf("head->next->next->next->prev->prev->name (second in list): %s\n",
    head->next->next->next->prev->prev->name);
  printf("head->next->next->next->prev->prev->prev->name (first in list): %s\n",
    head->next->next->next->prev->prev->prev->name);
  printf("\n");

  while (head != NULL) {
    printf("%s ", head->name);
    printf("%s ", head->id);
    printf("%d.%d.%d ", head->d, head->m, head->y);
    printf("%d\n", head->salary);
    head = head->next;
  }
}
void print (employee_t *head, int argc, char *argv[]) {
  employee_t *e = head;
  char ss[L];
  char sn[L];
  int i = 0;

  printf("\nprint function\n\n");

  sscanf(argv[3], "%s", ss);
  sscanf(argv[2], "%s", sn);
  printf("Pattern: %s\n", ss);
  printf("Name: %s\n\n", sn);

  while (e != NULL) {
    if (strcmp(sn, e->name) == 0) {
      printf("%s ", e->name);
      printf("%s ", e->id);
      printf("%d.%d.%d ", e->d, e->m, e->y);
      printf("%d\n", e->salary);
      while (i<strlen(ss)) {
        if (e->prev == NULL && ss[i] != 43){
          printf("%s ", e->name);
          printf("%s ", e->id);
          printf("%d.%d.%d ", e->d, e->m, e->y);
          printf("%d\n", e->salary);
          i++;
        } else if (e->next == NULL && ss[i]!= 45) {
          printf("%s ", e->name);
          printf("%s ", e->id);
          printf("%d.%d.%d ", e->d, e->m, e->y);
          printf("%d\n", e->salary);
          i++;
        } else if(ss[i] == 45){ /** 45 is "-" */
          printf("%s ", e->prev->name);
          printf("%s ", e->prev->id);
          printf("%d.%d.%d ", e->prev->d, e->prev->m, e->prev->y);
          printf("%d\n", e->prev->salary);
          e = e->prev;
          i++;
        } else if (ss[i] == 43){ /** 43 is "+" */
          printf("%s ", e->next->name);
          printf("%s ", e->next->id);
          printf("%d.%d.%d ", e->next->d, e->next->m, e->next->y);
          printf("%d\n", e->next->salary);
          e = e->next;
          i++;
        }
      }
      if (i == strlen(ss)){ return; }
    }
    e = e->next;
  }
}
