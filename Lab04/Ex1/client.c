#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100 + 1

typedef struct producer_s *producer_t;
typedef struct product_s *product_t;

struct producer_s {
  char *name;
  char *id;
  producer_t next;
  product_t prods;
};

struct product_s {
  char *name_item;
  int id_item;
  product_t next_item;
};

void check_args(int argc, char *argv[]);
producer_t scan_file(int argc, char *argv[]);
int file_num_of_line_completed(char *filename, char *mode, int n);
FILE *open_file(char *filename, char *mode);
void *malloc_ck(int size);
producer_t insert_comp(producer_t cc, char *__name, char *__id);
producer_t insert_item(producer_t p, char *__id_c, char *__name_car, int __n_car);
producer_t scan_list();
void display(producer_t c);

int main(int argc, char *argv[]) {
  check_args(argc, argv);
  scan_file(argc, argv);
  return 0;
}

void check_args(int argc, char *argv[]) {
  if (argc != 3) {
    perror("Error, not 3 args!");
  }
}

int file_num_of_line_completed(char *filename, char *mode, int N) {
  char *line;
  FILE *f;
  int n = 0;

  line = malloc_ck(C * sizeof(char));
  f = open_file(filename, mode);
  while (fgets(line, C, f) != NULL) {
    n++;
  }
  fclose(f);
  return n;
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


void *malloc_ck(int size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

producer_t scan_file(int argc, char *argv[]) {
  FILE *f1, *f2;
  int n1 = 0, n2 = 0, _n_car;
  char *_name, *_id, *_id_c, *_name_car;
  producer_t c = NULL;
  producer_t cc;

  _name = malloc_ck(20*sizeof(char));
  _id = malloc_ck(20*sizeof(char));
  _id_c = malloc_ck(20*sizeof(char));
  _name_car = malloc_ck(20*sizeof(char));
  n1 = file_num_of_line_completed(argv[1], "r", n1);
  n2 = file_num_of_line_completed(argv[2], "r", n2);
  f1 = open_file(argv[1], "r");
  f2 = open_file(argv[2], "r");

  for (int i = 0; i < n1; i++) {
    fscanf(f1, "%s %s", _name, _id);
    c = insert_comp(c, _name, _id);
  }

  for (int i = 0; i < n1; i++) {
    fscanf(f2, "%s %s %d", _id_c, _name_car, &_n_car);
    cc = scan_list(c, _id_c);
    cc = insert_item(cc, _id_c, _name_car, _n_car);
  }
  display(c);
  return c;
}

//producer , company
producer_t insert_comp(producer_t p, char *__name, char *__id){
  producer_t c = p;
  producer_t q;

  q = malloc_ck(sizeof(producer_t));
  q->name = strdup(__name);
  q->id = strdup(__id);
  q->next = c;
  c = q;
  return c;
}

//product item car
producer_t insert_item(producer_t p, char *__id_c, char *__name_car, int __n_car) {
  producer_t c = p;
  producer_t q;

  q = malloc_ck(sizeof(producer_t));
  q->prods = malloc_ck(sizeof(product_t));
  q->prods->name_item = strdup(__name_car);
  q->prods->id_item = __n_car;
  q->prods->next_item = c->prods;
  c->prods = q->prods;
  return c;
}

producer_t scan_list(producer_t c, char *_id_c) {
  producer_t cc = c;
  while (cc != NULL) {
    if (strcmp(cc->id, _id_c) == 0) {
      return cc;
    } else cc = cc->next;
  }
  return cc;
}

void display(producer_t head) {
  while (head != NULL) {
    printf("Company:\n");
    printf("%s %s\n", head->name, head->id);
    printf("Cars:\n");
    while (head->prods != NULL) {
      printf("%s %d\n", head->prods->name_item, head->prods->id_item);
      head->prods = head->prods->next_item;
    }
    printf("\n");
    head = head->next;
  }
}

/** Exercise 01 */
/** ----------- */
/**  */
/** A "producer" file includes a line for each car manufacturer with the */
/** following format: */
/** manufactuiredName id */
/** where manufacturerName and id are strings of 20 characters at most. */
/** The following is a correct example: */
/**  */
/** FIAT it001 */
/** ALFA_ROMEO it002 */
/** BMW ge001 */
/** MERCEDES ge002 */
/** TOYOTA ja001 */
/** ... */
/**  */
/** The size of the file, and the order of the lines within the file, are */
/** unknown. */
/**  */
/** A "product" file stores the product names and relative prices for each */
/** product of each manufacturer, with the format: */
/** id productName price */
/** The following one is a correct example: */
/**  */
/** it001 500 15131 */
/** it001 Panda 12001 */
/** it001 Punto 17891 */
/** ge002 AClass 22411 */
/** ge002 CClass 75641 */
/** ... */
/**  */
/** The size (and order) of the file is unknown. */
/**  */
/** Write a C program that: */
/** * receives two file names on the command line */
/** * stores the content of the two files (the first one of type "producer", */
/**   the second one of type "product") in a proper data structure */
/** * goes through an iteration in which it reads the name of a */
/**   manufacturer (e.g, FIAT) and it prints-out all products (and */
/**   relative prices) produced by it on standard output. */
/**  */
/** Suggestion */
/** ---------- */
/**  */
/** Implement a "list of lists", i.e., a main "producer" list with */
/** a secondary "product" list for each producer element. */
/**  */
/**  ------    ------    ------     */
/**  |    | -> |    | -> |    | -> ... product list */
/**  ------    ------    ------    */
/**    | */
/**    v */
/**  ------    ------   */
/**  |    | -> |    | -> ... */
/**  ------    ------    */
/**    | */
/**    v */
/** producer */
/**  list */
/**  ... */
/**  */
/** as with this data structure it is easy to find all products */
/** manufactured by a given producer. */

  /** printf("c->name (first in list): %s %s \n", c->name, c->id); */
  /** printf("c->next->name (second in list): %s %s\n", c->next->name, c->next->id); */
  /** printf("c->next->next->name (third in list): %s %s\n", c->next->next->name, c->next->next->id); */
  /** printf("c->next->next->next->name (fourth in list): %s %s\n", c->next->next->next->name, c->next->next->next->id); */
  /** printf("c->next->next->next->next->name (fifth in list): %s %s %s %d\n", */
  /**     c->next->next->next->next->name, c->next->next->next->next->id, c->next->next->next->next->prods->name_item, c->next->next->next->next->prods->id_item); */
