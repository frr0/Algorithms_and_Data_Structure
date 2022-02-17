#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 10
#define C 100 + 1

typedef struct aaa_s aaa_t;

struct aaa_s {
  char name[X];
  float x1;
  float y1;
  float x2;
  float y2;
  float perimeter;
  float area;
};

void arg_check(int argc, char *argv[]);
void scan_file();
int file_num_of_line_completed(char *filename, char *mode);
void *malloc_ck(int size);
FILE *open_file(char *filename, char *mode);

int main(int argc, char *argv[]) {
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

void scan_file(char *filename, char *mode) {
  aaa_t *tmp;
  FILE *f;
  int nL;
  char tmp_name[X];
  float tmp_x;
  float tmp_y;
  float h = 0;
  float b = 0;

  f = open_file(filename, mode);
  fscanf(f, "%d", &nL);
  nL = 2 * nL;
  tmp = malloc_ck(nL * sizeof(aaa_t));

  // stuff
  for (int a = 0; a < nL; a++) {
    tmp[a].x1 = 0;
    tmp[a].y1 = 0;
    tmp[a].x2 = 0;
    tmp[a].y2 = 0;
    tmp[a].perimeter = 0;
    tmp[a].area = 0;
  }

  /* core */
  for (int i = 0; i < nL; i++) {
    fscanf(f, "%s %f %f", tmp_name, &tmp_x, &tmp_y); // scan from file
    for (int j = 0; j < nL; j++) {
      if (strcmp(tmp_name, tmp[j].name) ==
          0) {             // check for name just scanned in struct
        tmp[j].x2 = tmp_x; // add the last two
        tmp[j].y2 = tmp_y;
        h = tmp[j].y2 - tmp[j].y1; // calc base
        b = tmp[j].x2 - tmp[j].x1; // calc hight
        h = fabs(h);
        b = fabs(b);
        tmp[j].perimeter = 2 * (h + b); // calc per
        tmp[j].area = h * b;            // calc area
        //--------------------------
        tmp[i].x1 =
            0; // equalize the values of the first time the name has been gotten
        tmp[i].x2 =
            0; // so that i can delete the empty line since one line is givene
        tmp[i].x2 = 0; // in two
        tmp[i].y2 = 0;
      }
    }
    strcpy(tmp[i].name, tmp_name); // if the word is not in struct, add it
    tmp[i].x1 = tmp_x;             // with the two values
    tmp[i].y1 = tmp_y;
  }
  fclose(f);
  FILE *f2;
  FILE *f3;
  aaa_t temp11;
  int j = 0;

  for (int i = 1; i < nL; i++) {
    temp11 = tmp[i];
    j = i;
    while ((--j >= 0) && (temp11.perimeter > tmp[j].perimeter)) {
      tmp[j + 1] = tmp[j];
    }
    tmp[j + 1] = temp11;
  }
  aaa_t temp22;
  j = 0;

  for (int i = 1; i < nL; i++) {
    temp22 = tmp[i];
    j = i;
    while ((--j >= 0) && (temp22.area > tmp[j].area)) {
      tmp[j + 1] = tmp[j];
    }
    tmp[j + 1] = temp22;
  }

  f2 = open_file("filePertmeter.txt", "w");
  f3 = open_file("fileArea.txt", "w");
  printf("\nName\tx1\ty1\tx2\ty2\tPerimeter\tArea\n");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  for (int k = 0; k < (nL); k++) {
    if (tmp[k].x2 != 0 && tmp[k].y2 != 0) {
      printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\n", tmp[k].name,
             tmp[k].x1, tmp[k].y1, tmp[k].x2, tmp[k].y2, tmp[k].perimeter,
             tmp[k].area);
      fprintf(f2, "%s\t%f\n", tmp[k].name, tmp[k].perimeter);
      fprintf(f3, "%s\t%f\n", tmp[k].name, tmp[k].area);
    }
  }

  fclose(f2);
  fclose(f3);
}

int file_num_of_line_completed(char *filename, char *mode) {
  char *line;
  FILE *f;
  int n = 0;

  line = malloc_ck(C * sizeof(char));
  f = open_file(filename, mode);

  while (fgets(line, C, f) != NULL) {
    n++;
  }

  fprintf(stdout, "\nNumber of lines: %d\n", n);

  fclose(f);

  return n;
}

void *malloc_ck(int size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
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
