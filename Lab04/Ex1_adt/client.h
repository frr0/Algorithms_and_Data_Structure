#ifndef _CLIENT
#define _CLIENT

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C 100 + 1
#define XX 20 + 1

typedef struct _producer *producer;
typedef struct _product *product;
typedef struct _id *id;

struct _producer {
  id next_comp;
  product prods;
  producer next;
};

struct _id {
  char *name_comp;
  char *id_comp;
};

struct _product {
  char *name_item;
  int id_item;
  product next_item;
};

#endif
