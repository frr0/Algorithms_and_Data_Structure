#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XX 20+1

void check_args(int argc, char *argv[]);
char ***scan_file(char ***mat, int argc, char *argv[]);
FILE *open_file(char *filename, char *mode);
char ***order(char ***mat, int rr, int cc);

int main(int argc, char *argv[])
{
  char ***mat = 0;

  check_args(argc, argv);
  mat = scan_file(mat, argc, argv);

  return 0;
}

void check_args(int argc, char *argv[]){
  if(argc != 3){
    perror("Error, not 3 args!");
    exit(-1);
  }
}

char ***scan_file(char ***mat, int argc, char *argv[]){
  FILE *f1;
  /** FILE *f2; */
  int r, c;
  char word[XX];

  f1 = open_file(argv[1], "r");
  /** f2 = open_file(argv[2], "w"); */

  fscanf(f1, "%d %d", &r, &c);

  mat = malloc(r * sizeof(char**));
  for(int i=0; i<r; i++){
    mat[i] = malloc(c * sizeof(char*));
    for(int j=0; j<c; j++){
      mat[i][j] = malloc(XX * sizeof(char));
      fscanf(f1, "%s", word);
      strcpy(mat[i][j], word);
      /** printf("%s", word); */
      printf("%s\n", mat[i][j]);
      /** fprintf(f2, "%s\n", mat[i][j]); */
    }
  }
  mat = order(mat, r,  c);
  return mat;
}

FILE *open_file(char *filename, char *mode){
  FILE *f = fopen(filename, mode);
  if (f == NULL){
    perror("Error, file opening error!");
    exit(-2);
  }
  return f;
}
char ***order(char ***mat, int rr, int cc){
  FILE *f2 = fopen("f2.txt", "w");
  int n = (rr*cc);
  char A[3][XX];
  char B[3][XX];
  char C[3][XX];
  char D[3][XX];
  /** char **A; */
  /** char **B; */
  /** char **C; */
  /** char **D; */
  char E[n][XX];
  int a = 0, b = 0, c = 0, d = 0;

  /** A = malloc(cc * sizeof(char*)); */
  /** B = malloc(cc * sizeof(char*)); */
  /** C = malloc(cc * sizeof(char*)); */
  /** D = malloc(cc * sizeof(char*)); */
  /**  */
  /** for (int z=0; z<cc; z++){ */
  /**   A[z] = malloc(XX * sizeof(char*)); */
  /**   B[z] = malloc(XX * sizeof(char*)); */
  /**   C[z] = malloc(XX * sizeof(char*)); */
  /**   D[z] = malloc(XX * sizeof(char*)); */
  /** } */


  printf("%d\n", cc);
  for (int i=0; i<rr; i++){
    for (int j=0; j<cc; j++){
      if (i == 0){
        strcpy(A[j], mat[i][j]);
      } else if (i == 1){
        strcpy(B[j], mat[i][j]);
      } else if (i == 2){
        strcpy(C[j], mat[i][j]);
      } else if (i == 3){
        strcpy(D[j], mat[i][j]);
      }
    }
  }

  printf("\n");
  printf("\n");
  printf("Cities in A, B, C, D array of array:\n");
  printf("\n");
  for (int k=0; k<cc; k++){
    printf("%s\n", A[k]);
    printf("%s\n", B[k]);
    printf("%s\n", C[k]);
    printf("%s\n", D[k]);
  }
  printf("\n");

  for(int i=0; i<n; i++){
    if ((strcmp(A[a], B[b]) < 0) && (strcmp(A[a], C[c]) < 0) && (strcmp(A[a], D[d]) < 0)) {
      strcpy(E[i], A[a]); if (a < 3) a++;
      printf("%s\n", E[i]);
      printf("e %d\n", i);
      printf("a %d\n", a-1);
    } else if ((strcmp(B[b], A[a]) < 0) && (strcmp(B[b], C[c]) < 0) && (strcmp(B[b], D[d]) < 0)){
      strcpy(E[i], B[b]); if (b < 3) b++;
      printf("%s\n", E[i]);
      printf("e %d\n", i);
      printf("b %d\n", b-1);
    } else if ((strcmp(C[c], A[a]) < 0) && (strcmp(C[c], B[b]) < 0) && (strcmp(C[c], D[d]) < 0)){
      strcpy(E[i], C[c]); if (c < 3) c++;
      printf("%s\n", E[i]);
      printf("e %d\n", i);
      printf("c %d\n", c-1);
    } else if ((strcmp(D[d], A[a]) < 0) && (strcmp(D[d], B[b]) < 0) && (strcmp(D[d], C[c]) < 0)){
      strcpy(E[i], D[d]); if (d < 3) d++;
      printf("%s\n", E[i]);
      printf("e %d\n", i);
      printf("d %d\n", d-1);
    }
  }

  printf("\n");
  printf("\n");
  printf("Cities in E array of array:\n");
  printf("\n");
  for (int i=0; i<n; i++){
    printf("%s\n", E[i]);
    fprintf(f2, "%s\n", E[i]);
  }
  return mat;
}
