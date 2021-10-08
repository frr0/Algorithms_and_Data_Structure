#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define N 5

void myf(char *, char *, int *);
void f (char *);
int display (float mat[][N], int n);
int palindrome1 (char *);
int palindrome2(char *);
void substring (char *, int *, int *);

//
//
//

int main (int argc, char *argv[]) {

  printf("############################\n");
    
#if 1
  {
  typedef struct item_s {
    char c1;
    int i1;
    char c2;
    int i2;
  } item_t;
  item_t myitem;

  printf ("sizeof(item_s) = %ld\n", sizeof (myitem));
  }
#endif
  
  printf("############################\n");
    
#if 1
  {
  int i = 10;
  int j = 20;
  int *p1 = &i;
  int *p2 = &j;

  if (p1==p2) printf ("T"); else printf ("F");
  if (*p1==*p2) printf ("T"); else printf ("F");
  if (p1>=p2) printf ("T"); else printf ("F");
  if (p1<=p2) printf ("T"); else printf ("F");
  if (p1!=p2) printf ("T"); else printf ("F");
  if (*p1!=*p2) printf ("T"); else printf ("F");
  printf ("\n");
  }
#endif

  printf("############################\n");
    
#if 1
  {
  char s1[]="string";
  char s2[6]={'s','t','r','i','n','g'};
  char *p1="string";

  printf ("%ld %ld %ld %ld\n", sizeof(s1), sizeof(s2), sizeof(p1), sizeof(*p1));
  }
#endif

  printf("############################\n");
  
#if 1
  {
  char in[] = "This is a very loooong string";
  char out[50];
  int n;
  myf (in, out, &n);
  printf("myf: %s %d\n", out, n);
  }
#endif

  printf("############################\n");
    
#if 1
  {
  char s[] = "This 12345 is a string";
  f (s);
  printf("f: %s\n", s);
  }
#endif

  printf("############################\n");
  
#if 1
  {
  int i, j, k;
  float mat[N][N];

  k = 1;		    
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
       mat[i][j] = k++;


  printf ("Mat:\n");
  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      printf ("%3d ", (int) mat[i][j]);
    }
    printf ("\n");
  }

  display (mat, N);
  }
#endif

  printf("############################\n");
    
#if 1
  {
  fprintf (stdout, "Palindrome 1: %d\n", palindrome1 ("1234554abccbaxxYY"));
  fprintf (stdout, "Palindrome 2: %d\n", palindrome2 ("1234554abccbaxxYY"));
  }
#endif

  printf("############################\n");

#if 1
  {
  char str[] = "This is 1 string inclUding diGIts: 12345 678 9";
  int letter, digit;
  substring (str, &letter, &digit);  
  printf("substring: %d %d\n", letter, digit);
  }
#endif

  printf("############################\n");
  
  return 1;
}

//
//
//

void myf (char* in, char* out, int* n) {
    char* tmp1, * tmp2;
    int l;

    out[0] = '\0';
    tmp1 = in;
    while (*tmp1 != '\0') {
        while (*tmp1 == ' ') {
            tmp1++;
        }
        tmp2 = tmp1;
        while (*tmp2 != ' ' && *tmp2 != '\0') {
            tmp2++;
        }
        l = tmp2 - tmp1;
        if (l > strlen(out)) {
            *n = l;
            strncpy(out, tmp1, l);
            out[l] = '\0';
        }
        tmp1 = tmp2;
    }

    return;
}

//
//
//

void f (char *s) {
  int i, j;

  i = 0;
  while (i < strlen(s)) {
    if (s[i]==' ' || (s[i]>='0' && s[i]<='9')) {
      for (j=i+1; j<strlen(s)+1; j++) s[j-1] = s[j];
   } else {
      i = i + 1;
    }
  }

  return;
}

//
//
//

int display (float mat[][N], int n) {
  int i, j, k;

  for (k=0; k<n; k++) {
    j = k;
    for (i=0; i<n && j>=0; i++, j--) {
      fprintf (stdout, "%f ", mat[i][j]);
    }
  }

  for (k=1; k<n; k++) {
    i = k;
    for (j=n-1; i<n && j>=0; i++, j--) {
      fprintf (stdout, "%.2f ", mat[i][j]);
    }
  }
  fprintf (stdout, "\n");

  return 1;
}

//
//
//

int palindrome1 (char *str) {
  int i, j, k, l, lm, s;

  s = lm = 0;
  for (i=0; i<strlen (str); i++) {
    for (j=strlen (str)-1; j>i; j--) {
      l = 0;
      for (k=0; k<=((j-i+1)/2); k++) {
        if (str[i+k]==str[j-k]) {
          l+=2;
        } else {
          break;
        }
      }
      if (l>lm) {
        s = i;
        lm = j-i+1;
      }
    }
  }

  if (lm!=0) {
    fprintf (stdout, "Longest substrig: ");
    for (i=s; i<s+lm; i++) {
      fprintf (stdout, "%c", str[i]);
    }
    fprintf (stdout, " --> ");
  }

  return lm;
}

int palindrome2 (char *str) {
  int i, l, r, len, lenm;

  lenm = 0;
  for (i=0; i<strlen (str); i++) {
    l = r = i;
    len = -1;
    while (l>=0 && r<strlen(str)) {
      if (str[l]==str[r]) {
        len*=2; l--; r++; len+=2;
      } else {
        break;
      }
    }
    if (len>lenm)
      lenm = len;
    l = i; r = i+1;
    len = 0;
    while (l>=0 && r<strlen(str)) {
      if (str[l]==str[r]) {
        len+=2; l--; r++;
      } else {
        break;
      }
    }
    if (len>lenm)
      lenm = len;
  }

  return lenm;
}

//
//
//

void substring (char *str, int *letter, int *digit) {
  int i, l, d;

  *letter = l = 0;
  *digit = d = 0;  
  for (i=0; i<strlen(str); i++) {
    if (str[i]>='a' && str[i]<='z') {
      l++;
    } else {
      if (l>*letter)
	*letter = l;
      l = 0;
    }

    if (str[i]>='0' && str[i]<='9') {
      d++;
    } else {
      if (d>*digit)
	*digit = d;
      d = 0;
    }
  }
  
  return;
}
