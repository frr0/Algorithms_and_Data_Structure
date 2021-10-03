#include <stdio.h>
#include <stdlib.h>

#define X 10

int main(int argc, char *argv[])
{
  int v[X];
  int *p;

  p = &v;

  for(int i=0; i<X; i++, p++){
    scanf("%d", p);
    printf("%d\n", *p);
  }


  return 0;
}
