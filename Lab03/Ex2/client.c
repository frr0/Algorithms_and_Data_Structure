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
  if (argc != 3){
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
    printf("%s\n", head->name);
    printf("%s\n", head->id);
    printf("%d.%d.%d\n", head->d, head->m, head->y);
    printf("%d\n", head->salary);
    head = head->next;
  }
}
void print (employee_t *head, int argc, char *argv[]) {
  char ss[L];
  char c;

  sscanf(argv[2], "%s", ss);
  while (sscanf(ss, "%c", &c) == EOF){
    if(c == 45){
      printf("%s\n", head->prev->name);
      printf("%s\n", head->prev->id);
      printf("%d.%d.%d\n", head->prev->d, head->prev->m, head->prev->y);
      printf("%d\n", head->prev->salary);
    } else if (c == 43){
      printf("%s\n", head->next->name);
      printf("%s\n", head->next->id);
      printf("%d.%d.%d\n", head->next->d, head->next->m, head->next->y);
      printf("%d\n", head->next->salary);
    }
  }
}

/** Exercise 02 */
/** ----------- */
/**  */
/** A file contains data on a set of employees. */
/** For each employee there is a row of the file, including: */
/** * Last and first name (a single C string, maximum 50 characters, */
/**   e.g., Smith_John). */
/** * Personal identification (exactly 16 characters). */
/** * Data of hiring (format dd.mm.yyy, e.g, 30.05.2005). */
/** * Salary (integer value, in euro). */
/** Fields are space-separated. */
/** Employees do not appear in any specific order. */
/**  */
/** A C program receives 3 parameters on the command line: */
/** * Input file name (the format is the previously defined one). */
/** * A single strings, representing a last and first name pair (e.g., */
/**   Clinton_Bill). */
/** * A string made of only + and - characters (e.g., +++---+-+). */
/**  */
/** The program has to: */
/** * Read the file. */
/** * Store its content in a LIFO-logic list, but with two pointers for */
/**   each element one pointing ahead and one pointing behind the element */
/**   itself as: */
/**  */
/**   pHead  --> ----- --> ----- --> ----- --> ----- -X */
/**              |###|     |###|     |###|     |###| */
/**           X- ----- <-- ----- <-- ----- <-- ----- */
/**  */
/** * Find in the list the element storing the employee whose name is */
/** * passed on the command line as a second parameter. */
/** * Move along the list in the */
/**   - right direction for each '+' character */
/**   - left direction for each '-' character */
/**   in the third string parameter. */
/**   For each visited node of the list (including the first one) the */
/**   program has to print out (on standard output) all data of the */
/**   employee (with the same format this data appears in the original */
/**   input file). */
/**   If the end of the list is reached (in either side) the program has to */
/**   print-out the same element repeatedly. */
/**  */
/** Example */
/** ------- */
/**  */
/** Let the command line parameters be the following */
/**  */
/** file.txt Giallo_Antonio ---+ */
/**  */
/** and the file be the following */
/**  */
/** Rossi_Alberto AAABBBCCDEEFGGGH 03.12.1998 1845 */
/** Giallo_Antonio AAABBBCCDEEFGGGH 13.11.2007 1140 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/**  */
/** The file has to be stored in the LIFO structure as: */
/** Bianchi  ->  Verdi  -> Giallo  -> Rossi   */
/** Then, the program has to: */
/** - find Giallo_Antonio in the list and print its data */
/** - move let on Verdi and print its data (first -) */
/** - move left again and print Bianchi (second -) */
/** - do not move and print Bianchi again (third -) */
/** - move right and print Verdi (first +): */
/**  */
/** Giallo_Antonio AAABBBCCDEEFGGGH 13.11.2007 1140 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/**  */
