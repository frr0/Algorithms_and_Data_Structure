#ifndef _UTIL
#define _UTIL

#include "client.h"

void check_args(int argc, char **argv);
FILE *open_file(char *filename, char *mode);
char *malloc1d_ck(int r);
char **malloc2d_ck(int r, int c);

#endif
