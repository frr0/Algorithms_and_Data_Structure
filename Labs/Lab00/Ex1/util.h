#ifndef _UTIL
#define _UTIL

#include <stdio.h>

#define C 100+1
#define II 20+1

void arg_check(int argc, char *argv[]);
FILE *open_file(char* filename, char* mode);
void read_words(char *filename, char *mode, int N);
int Search_words(char *filename, char *mode, int N);
void *malloc_ck(int size);
char **mat_allocation(int c, int r);

#endif
