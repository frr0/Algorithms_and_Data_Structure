#ifndef _CLIENT
#define _CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "util.h"

#define DEBUG 0

// typedef struct name_s *name_t;

typedef struct {
  char word[II];
  int occurrences;
}name_t;

#endif
