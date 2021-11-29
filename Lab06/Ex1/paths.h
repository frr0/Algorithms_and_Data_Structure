#ifndef _PATHS
#define _PATHS

#include "client.h"
#include "mat.h"

#define R 12
#define C 10

void printmat2(char **m);
int escape1(char **m, char **mm, int r, int c);
int escape2(char **m, int r, int c);
int escape3(char **m, int r, int c);

#endif
