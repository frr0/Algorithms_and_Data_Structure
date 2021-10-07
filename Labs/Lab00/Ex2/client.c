#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 10
#define C 100+1

typedef struct aaa_s aaa_t;

struct aaa_s{
  char name[X];
  float x1;
  float y1;
  float x2;
  float y2;
float perimeter;
float	area;
};

void arg_check(int argc, char *argv[]);
void scan_file();
int file_num_of_line_completed(char *filename, char *mode);
void *malloc_ck(int size);
FILE *open_file(char *filename, char *mode);

int main(int argc, char *argv[])
{
  arg_check(argc, argv);
	scan_file(argv[1], "r");

  return 0;
}

void arg_check(int argc, char *argv[]) {
  if (argc != 4) // checking argc
  {
    printf("Error, not 4 args");
    exit(-1);
  }
}

void scan_file(char *filename, char *mode){
  aaa_t tmp[X];
  FILE *f;
	int nL;
	char tmp_name[X];
	float tmp_x;
	float tmp_y;
	float h = 0;
	float b = 0;
	
	f = open_file(filename, mode);
	//count # of lines
	nL = file_num_of_line_completed(filename, "r");
	fclose(f);
	f = open_file(filename, mode);

	//stuff
	for(int a=0; a<nL; a++){
		tmp[a].x1 = 0;
		tmp[a].y1 = 0;
		tmp[a].x2 = 0;
		tmp[a].y2 = 0;
		tmp[a].perimeter = 0;
		tmp[a].area = 0;
	}

	/* core */
	for(int i = 0; i<nL; i++){	
		fscanf(f, "%s %f %f", tmp_name, &tmp_x, &tmp_y);
		for(int j = 0; j<nL; j++){
			/* if(tmp_name == tmp[i].name){ */
			/* for(int z = 0; z<nL; z++){ */
				/* if(tmp_name[z] == tmp[j].name[z]){ */
					/* tmp[i].x2 = tmp_x; */
					/* tmp[i].y2 = tmp_y; */
					/* h = tmp[i].x2-tmp[i].x1; */
					/* b = tmp[i].y2-tmp[i].y1; */
					/* tmp[i].perimeter = 2*(h+b); */
					/* tmp[i].area = h*b; */
				/* } */
			/* } */
			if(strcmp(tmp_name, tmp[j].name) == 0){
				tmp[i].x2 = tmp_x;
				tmp[i].y2 = tmp_y;
				h = tmp[i].x2-tmp[i].x1;
				b = tmp[i].y2-tmp[i].y1;
				tmp[i].perimeter = 2*(h+b);
				tmp[i].area = h*b;
			}
		}
		strcpy(tmp[i].name, tmp_name);
		tmp[i].x1 = tmp_x;
		tmp[i].y1 = tmp_y;
	}
	fclose(f);
	printf("\nName\tx1\t  \ty1\t  \tx2\t  \ty2\t  \tPerimeter\tArea\n");
	printf("------------------------------------------------------------------------------------------------\n");
	for(int k = 0; k<(nL); k++){	
		printf("%s\t%f\t%f\t%f\t%f\t%f\t%f\n", tmp[k].name, tmp[k].x1, tmp[k].y1, tmp[k].x2, tmp[k].y2, tmp[k].perimeter, tmp[k].area);
	}
}

int file_num_of_line_completed(char *filename, char *mode){
	char *line;
	FILE *f;
	int n=0;

	line = malloc_ck(C*sizeof(char));
	f = open_file(filename, mode);

	while(fgets(line, C, f) != NULL)
	{
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

FILE *open_file(char *filename, char *mode) {
  FILE *f;
  f = fopen(filename, mode);
  if (!f) {
    perror(filename);
    exit(EXIT_FAILURE);
  }

  return f;
}
