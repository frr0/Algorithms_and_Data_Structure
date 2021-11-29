#ifndef _MAT
#define _MAT

#include "client.h"

char **scanmat(int argc, char **argv);
void printmat(char **m, int argc, char **argv);
void printmat2(char **m);
void dim2(int r, int c,int argc, char **argv);
void check_args(int argc, char **argv);
FILE *open_file(char *filename, char *mode);
char *malloc1d_ck(int r);
char **malloc2d_ck(int r, int c);
void dim(int *r, int *c, int argc, char **argv);
int escape1(char **m, char **mm, int r, int c);
int escape2(char **m, int r, int c);
int escape3(char **m, int r, int c);

#endif
