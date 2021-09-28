#include "client.h"
#include "util.h"
#include <stdio.h>

void arg_check(int argc, char *argv[])
{
    if(argc!=3)//checking argc
    {
        printf("Error, not 3 args");
        exit(-1);
    }
}

FILE *open_file(char* filename, char* mode)
{
    FILE *f;
    f = fopen(filename, mode);
    if(!f)
    {
        perror(filename);
        exit(EXIT_FAILURE);
    }

    return f;
}

int file_num_of_line_completed(char *filename, char *mode, int N)
{
    char *line;
    char *word;
    FILE *f;
	  int n=0;
	  int m=0;

    line = malloc_ck(C*sizeof(char));
    word = malloc_ck(C*sizeof(char));
    open_file(filename, "r");

	while(fgets(line, C, f) != NULL)
	{
    while (sscanf(line, "%s ", word)) {
      m++;
    }
		n++;
	}

	fprintf(stdout,"\nNumber of lines: %d\n", n);

	fclose(f);

    return n;

}

void *malloc_ck(int size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL){
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}

void storefile()
{
  /** while(fscanf(f, , ...)) */
}
