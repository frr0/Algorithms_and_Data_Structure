#ifndef _UTIL
#define _UTIL

#include <stdio.h>

#define C 100+1
#define II 20+1

void arg_check(int argc, char *argv[]);
FILE *open_file(char* filename, char* mode);
int file_num_of_line_completed1(char *filename, char *mode, int N);
int file_num_of_line_completed2(char *filename, char *mode, int N);
void *malloc_ck(int size);
char **mat_allocation(int c, int r);
void storefile();

#endif
