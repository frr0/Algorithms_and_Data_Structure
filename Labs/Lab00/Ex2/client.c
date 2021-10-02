#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
/**   float *ptr; */
/** float f = 7.5; */
/**  */
/** int *ppp; */
/** int a = 3; */
/**  */
/** ptr = &f; */
/** ppp = &a; */
/**  */
/** printf("%f\n%f\n", f, *ptr);  */
/** printf("%d\n%d\n%d\n", (long unsigned int) &a, &(*ppp), ppp);  */

  
  int v = 5;
  int *p;
  p = &v;

  printf("%d\n", v);
  /** printf("%d\n", *v); */
  printf("%lu\n", (long unsigned int) &v);
  printf("%lu\n", (long unsigned int) &v);
  printf("%lu\n", (long unsigned int) p);
  printf("%d\n", *p);
  printf("%lu\n", (long unsigned int) &p);
  printf("%d\n", *(&v));
  /** printf("%d\n", &(*v)); */
  printf("%lu\n", (long unsigned int) *(&p));
  printf("%lu\n", (long unsigned int) &(*p));

  return 0;
}
