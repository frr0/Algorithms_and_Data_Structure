#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 10 + 1

typedef struct stuff_s {
  char name[X];
  int id;
  int nLap;
  float average;
  float tot;
  float *times;
} stuff_t;

void arg_check(int argc, char *argv[]);
stuff_t *scan_file();
int file_num_of_line_completed(char *filename, char *mode);
void *malloc_ck(int size);
FILE *open_file(char *filename, char *mode);

int main(int argc, char *argv[]) {
  int a;
  int nL;
  char nameC[X];

  stuff_t *cyclist;
  arg_check(argc, argv);
  cyclist = scan_file(argv[1], "r", &nL);
  printf("%d\n", nL);

  do {
    printf("Press 1 to list the cyclists\n");
    printf("Press 2 to see cyclist stuff\n");
    printf("Press 3 to see the ranking\n");
    printf("Press 0 to quit\n");
    printf("Enter #: ");
    scanf("%d", &a);
    if (a == 1) {
      for (int i = 0; i < nL; i++) {
        printf("%s %d %d\n", cyclist[i].name, cyclist[i].id, cyclist[i].nLap);
        for (int j = 0; j < cyclist[i].nLap; j++) {
          printf("%f\n", cyclist[i].times[j]);
        }
      }
    } else if (a == 2) {
      printf("Enter cyclist name: \n");
      scanf("%s", nameC);
      for (int i = 0; i < nL; i++) {
        if (strcmp(nameC, cyclist[i].name) == 0) {
          printf("%s %d %d\n", cyclist[i].name, cyclist[i].id, cyclist[i].nLap);
          for (int j = 0; j < cyclist[i].nLap; j++) {
            printf("%f\n", cyclist[i].times[j]);
          }
        }
      }
    } else if (a == 3) {
      for (int i = 0; i < nL; i++) {
        cyclist[i].tot = 0;
        printf("%d\n", cyclist[i].nLap);
        for (int j = 0; j < cyclist[i].nLap; j++) {
          cyclist[i].tot = cyclist[i].tot + cyclist[i].times[j];
        }
        cyclist[i].average = cyclist[i].tot / cyclist[i].nLap;
        printf("%s %d %d\n", cyclist[i].name, cyclist[i].id, cyclist[i].nLap);
        printf("%f\n", cyclist[i].average);
      }
      int j;
      float x;
      for (int k = 1; k < nL; k++) {
        x = cyclist[k].average; // first unsorted number
        j = k - 1;              // J=0: only sorted numbers
        while (j >= 0 && x < cyclist[j].average) {
          cyclist[j + 1].average =
              cyclist[j].average; // A[j] is not the smallest so it has to let
                                  // the other go to left ex A[j
          j--; // j=-1
        }
        cyclist[j + 1].average = x; // A[j+1=0]
      }
      printf("%s %d %d\n", cyclist[0].name, cyclist[0].id, cyclist[0].nLap);
      printf("%f\n", cyclist[0].average);
    } else if (a == 0) {
      return 0;
    }
  } while (a != 0);

  return 0;
}

void arg_check(int argc, char *argv[]) {
  if (argc != 2) // checking argc
  {
    printf("Error, not 2 args\n");
    exit(-1);
  }
}

stuff_t *scan_file(char *filename, char *mode, int *nL) {

  FILE *f;
  stuff_t *cyclist;

  f = open_file(filename, mode);
  fscanf(f, "%d\n", nL);

  cyclist = malloc(*nL * sizeof(struct stuff_s));

  for (int i = 0; i < (*nL); i++) {
    fscanf(f, "%s %d %d\n", cyclist[i].name, &cyclist[i].id, &cyclist[i].nLap);
    cyclist[i].times = (float *)malloc(cyclist[i].nLap * sizeof(float));

    for (int j = 0; j < cyclist[i].nLap; j++) {
      fscanf(f, "%f", &cyclist[i].times[j]);
    }
  }
  return cyclist;
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
