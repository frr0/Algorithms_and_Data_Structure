#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define MAX 21

/* structure declaration */
typedef struct activity {
  char name[MAX];
  int start, stop;
  int selected;
} activity_t;


/* function prototypes */
activity_t *load(char *filename, int *num);
int cmp(const void *p1, const void *p2);
void choose(activity_t *acts, int n);
void display(activity_t *acts, int n);

/*
 *  main program
 */
int main(int argc, char *argv[])
{
  activity_t *acts;
  int n;

  util_check_m(argc>=2, "missing parameter.");
  acts = load(argv[1], &n);
  qsort((void *)acts, n, sizeof(activity_t), cmp);
  choose(acts, n);
  display(acts, n);
  free(acts);
  return EXIT_SUCCESS;
}

/*
 *  load the activities' descriptions from file
 */
activity_t *load(char *filename, int *num)
{
  activity_t *acts;
  int i, n;
  FILE *fp;

  fp = util_fopen(filename, "r");
  fscanf(fp, "%d", &n);
  acts = (activity_t *)util_malloc(n*sizeof(activity_t));
  for (i=0; i<n; i++) {
    fscanf(fp, "%s %d %d", acts[i].name, &acts[i].start, &acts[i].stop);
    acts[i].selected = 0;
  }
  fclose(fp);

  *num = n;
  return acts;
}

/*
 *  compare two activities on their stop time
 */
int cmp(const void *p1, const void *p2)
{
  activity_t *a1 = (activity_t *)p1;
  activity_t *a2 = (activity_t *)p2;

  return a1->stop - a2->stop;
}

/*
 *  select the activities to perform
 */
void choose(activity_t *acts, int n)
{
  int i, stop;

  acts[0].selected = 1;
  stop = acts[0].stop;
  for (i=1; i<n; i++) {
    if (acts[i].start >= stop) {
      acts[i].selected = 1;
      stop = acts[i].stop;
    }
  }
}

/*
 *  select the activities to perform
 */
void display(activity_t *acts, int n)
{
  int i;

  for (i=0; i<n; i++) {
    if (acts[i].selected != 0) {
      printf("Selected activity: %s ", acts[i].name);
      printf("[%d,%d)\n", acts[i].start, acts[i].stop);
    }
  }
}
