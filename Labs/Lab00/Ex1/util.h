#ifndef _UTIL
#define _UTIL

#include <stdio.h>

#define C 100+1

void arg_check(int argc, char *argv[]);
FILE *open_file(char* filename, char* mode);
int file_num_of_line_completed(char *filename, char *mode, int N);
void *malloc_ck(int size);
void storefile();

#endif
