#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int mult(int x, int y);
void d2b(int d, int *b, int *n);
int catalan(int n);
int countSpaces(char *s);
int isPalindrome(char *s, int l);
void triangle1(int n);
void triangle2(int n);

int main(int argc, char *argv[]) {
  int res, a = 17, *b, n = 2, c, p;
  char s[12] = {"a b c d e f"};

  c = countSpaces(s);
  printf("spaces = %d", c);

#if DEBUG
  res = mult(4, 3);
  printf("%d\n", res);
  d2b(14, b, &n);
  c = catalan(6);
  p = isPalindrome(char *s, int l);
  triangle1(int n);
  triangle2(int n);
#endif

  return 0;
}

/** A. */
/** Function */
/** res = mult (x, y); */
/** to multiply two integer numbers x and y, and to return the result */
/** res. */
/**  */
/** Notice that the elementary algorithm to perform multiplication is */
/** based on a sum-and-shift process. */
/** Anyway, mult may adopt the following recursive definition: */
/** x * y = x * (y-1) */
/** x * 1 = x */
/**  */
int mult(int x, int y) {
  /** static int i = 0; */
  static int r = 0;
  if (y == 0) {
    return x;
  }
  r = r + x;
  return mult(x, y - 1);
}

/** B. */
/** Function */
/** void d2b (int d, int *b, int *n); */
/** to convert the decimal number d, into a binary one (stored into the */
/** apply the "division" algorithm as follows: */
/**  */
/**    :2 */
/** 23 |  */
/** 11 | 1 */
/**  5 | 1 */
/**  2 | 1 */
/**  1 | 0 */
/**  0 | 1 */
/**  */
/** such that: */
/** 23 (base 10) = 10111 (base 2) */
/** Suppose that the size of the binary array is always sufficient to */
/** store all binary digits. */
/** Each call to the recursive function must generate and store into the */
/** array one single bit of the result. */
/**  */

void d2b(int d, int *b, int *n) {
  int a;
  a = d % (*n);
  d = d / (*n);
  printf("%d", a);
  if (d == 0) {
    return;
  }
  d2b(d, b, n);
}

/** C. */
/** Function */
/** int catalan (int n); */
/** to compute and to return the Catalan number of order n. */
/**  */
/** Catalan numbers are a sequence of numbers which can be defined */
/** directly or recursively. */
/** The recursive definition is the following one: */
/**  */
/** C_0 = 1     for n=0 */
/** and */
/** C_{n} = sum_{i=0}^{i=(n-1)} (C_i * C_{n-1-i})     for n>=1 */
/**  */
/** Write a program that, using a recursive function to generate Catalan
 * numbers, */
/** prints out the first 10 Catalan numbers. */

/** Observation */
/** ----------- */
/** sum indicates the summation symbol, i.e., */
/** sum_{i=0}^{i=(n-1)} (C_i * C_{n-1-i}) */
/** indicates the addition sequence of the numbers (C_i * C_{n-1-i}) */
/** for all values of i from i=0 to i=n-1: */

/** C_0 = 1 */
/** C_1 = C_0*C_0 = 1 */
/** C_2 = C_0*C_1 + C_1*C_0 = 2 */
/** C_3 = C_0*C_2 + C_1*C_1 + C_2*C_0 = 5 */
/** C_4 = C_0*C_3 + C_1*C_2 + C_2*C_1 + C_3*C_0 = 14 */
/** C_5 = C_0*C_4 + C_1*C_3 + C_2*C_2 + C_3*C_1 + C_4*C_0 = 42 */
/** C_6 = C_0*C_5 + C_1*C_4 + C_2*C_3 + C_3*C_2 + C_4*C_1 + C_5*C_0 = 132 */
/** ... */
/**  */
int catalan(int n) {
  static int i = 0;
  static int c = 0;

  if (n)
    return c;

  c = catalan(n - 1);

  return n;
}
/** D. */
/** Function */
/** int countSpaces (char *s); */
/** which counts and returns the number of white-space characters that */
/** appear in a string s. */
/** Notice that, characters are white-space as defined by the isspace() */
/** function within the ctype library. */
/**  */
/** Observation */
/** ----------- */
/** If a string str is read with command */
/** scanf ("%d", str); */
/** it cannot includes spaces as the reading operation actually stops when */
/** it reaches a space. */
/** Use the function gets to read a string with spaces, or define and */
/** initialize the string as: */
/** char str[] = "This is a string with spaces!"; */
/**  */
int i = 0;
int countSpaces(char *s) {
  static int n = 0;
  if (*s == 0) {
    return n;
  }
  if (isspace(*s)) {
    n++;
  }
  i++;
  n = countSpaces(s++);
  return -1;
}
/** E. */
/** Function */
/** int isPalindrome (char *s, int l);  */
/** that takes a string s and its length l as arguments and recursively */
/** determines whether the string is palindrome. */
/**  */
/** Observation */
/** ----------- */
/** A sequence is palindrome when the sequence of characters or numbers */
/** looks the same forwards and backwards. */
/** For example the strings */
/** Madam, I'm Adam */
/** A man, a plan, a canal, Panama */
/** are palindrome (excluding spaces and commas and considering capital */
/** equal to small letters), because they are spelled the same way reading */
/** them from front to back or from back to front. */
/** The number 12321 is a numerical palindrome. */
/**  */
int isPalindrome(char *s, int l) { return l; }
/** F. */
/** Function */
/** void triangle (int n, ...);  */
/** that given and integer value n (and any other parameters considered as */
/** necessary) prints-out a triangle containing increasing integer */
/** numbers. */
/** For example, for n=4, the program has to print-out */
/**  */
/** 1 */
/** 2 2 */
/** 3 3 3 */
/** 4 4 4 4 */
/**  */
/** Suggestion */
/** ---------- */
/**  */
/** Use an iterative construct (along each row) plus a recursion mechanism */
/** to move on the subsequent row. */
/**  */
void triangle1(int n) {}
/** G. */
/** Implement the previous function */
/** void triangle (int n, ...);  */
/** without using any iterative construct, i.e., using recursion */
/** to "move" along both rows and columns of the triangle. */
void triangle2(int n) {}
