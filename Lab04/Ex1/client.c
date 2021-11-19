#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100 + 1
#define XX 20 + 1

typedef struct producer *producer;
typedef struct product *product;
typedef struct id *id;

struct producer {
  id next_comp;
  product prods;
  producer next;
};

struct id {
  char *name_comp;
  char *id_comp;
};

struct product {
  char *name_item;
  int id_item;
  product next_item;
};

void check_args(int argc, char *argv[]);
FILE *open_file(char *filename, char *mode);
void *malloc_ck(int size);
int file_num_of_line_completed(char *filename, char *mode);
producer scan_file(int argc, char *argv[]);
producer insert_comp(producer p, char *__name, char *__id);
producer insert_item(producer p, char *__id_c, char *__name_car, int __n_car);
producer scan_list(producer p, char *_id_c);
void display(producer p);
void free_list(producer p);

int main(int argc, char *argv[]) {
  check_args(argc, argv);
  scan_file(argc, argv);
  return 0;
}

void check_args(int argc, char *argv[]) { assert(argc == 3); }

FILE *open_file(char *filename, char *mode) {
  FILE *f = fopen(filename, mode);
  assert(f != NULL);
  return f;
}

void *malloc_ck(int size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);
  return ptr;
}

int file_num_of_line_completed(char *filename, char *mode) {
  char *line;
  FILE *f;
  int n = 0;

  line = malloc_ck(C * sizeof(char));
  f = open_file(filename, mode);
  while (fgets(line, C, f) != NULL) {
    n++;
  }
  fclose(f);
  free(line);
  return n;
}

producer scan_file(int argc, char *argv[]) {
  FILE *f1, *f2;
  int n1 = 0, n2 = 0, _n_car;
  char *_name, *_id, *_id_c, *_name_car;
  producer p = NULL;
  producer c;

  _name = malloc_ck(XX * sizeof(char));
  _id = malloc_ck(XX * sizeof(char));
  _id_c = malloc_ck(XX * sizeof(char));
  _name_car = malloc_ck(XX * sizeof(char));

  n1 = file_num_of_line_completed(argv[1], "r");
  n2 = file_num_of_line_completed(argv[2], "r");
  f1 = open_file(argv[1], "r");
  f2 = open_file(argv[2], "r");

  for (int i = 0; i < n1; i++) {
    fscanf(f1, "%s %s", _name, _id);
    p = insert_comp(p, _name, _id);
  }

  for (int i = 0; i < n2; i++) {
    fscanf(f2, "%s %s %d", _id_c, _name_car, &_n_car);
    c = scan_list(p, _id_c);
    c = insert_item(c, _id_c, _name_car, _n_car);
  }

  display(p);

  free(_name);
  free(_id);
  free(_id_c);
  free(_name_car);
  free_list(c);

  return p;
}

/** producer , company */
producer insert_comp(producer p, char *__name, char *__id) {
  producer c = p;
  producer q;

  q = malloc_ck(sizeof(producer));
  q->next_comp = malloc_ck(sizeof(id));
  q->next_comp->name_comp = strdup(__name);
  q->next_comp->id_comp = strdup(__id);
  q->next = c;
  c = q;
  return c;
}

/** product item car */
producer insert_item(producer p, char *__id_c, char *__name_car, int __n_car) {
  producer c = p;
  producer q;

  q = malloc_ck(sizeof(producer));
  q->prods = malloc_ck(sizeof(product));
  q->prods->name_item = strdup(__name_car);
  q->prods->id_item = __n_car;
  q->prods->next_item = c->prods;
  c->prods = q->prods;
  return c;
}

producer scan_list(producer p, char *_id_c) {
  producer c = p;
  while (c != NULL) {
    if (strcmp(c->next_comp->id_comp, _id_c) == 0) {
      return c;
    } else
      c = c->next;
  }
  return c;
}

void display(producer p) {
  producer c = p;
  while (c != NULL) {
    printf("Company:\n");
    printf("%s %s\n", c->next_comp->name_comp, c->next_comp->id_comp);
    printf("Cars:\n");
    while (c->prods != NULL) {
      printf("%s %d\n", c->prods->name_item, c->prods->id_item);
      c->prods = c->prods->next_item;
    }
    printf("\n");
    c = c->next;
  }
}

void free_list(producer p) {
  producer c1 = p, c2;
  product t1 = p->prods, t2;
  id i = p->next_comp;

  while (c1 != NULL) {
    while (t1 != NULL) {
      t2 = t1->next_item;
      free(t2->name_item);
      free(t2);
      free(i->id_comp);
      free(i->name_comp);
      free(i);
      t1 = t2;
    }
    c2 = c1->next;
    free(c1);
    c1 = c2;
  }
}
