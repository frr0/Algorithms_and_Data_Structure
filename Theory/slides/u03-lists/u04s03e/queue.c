#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR    10

#define SUCCESS 2
#define FAILURE 3

struct e {
  int key;
  /* ... other data fields ... */
  struct e *next;
  };

struct e *enqueue (struct e *pTail, int val);
struct e *dequeue (struct e *pTail, int *val, int *status);
struct e *newE (  );
void traversal (struct e *pTail);
void read (int *val);
void write (int val, int status);

int
main (
  void
  )
{
  char choice[MAX_STR];
  struct e *pTail;
  int val, status;

  pTail = NULL;

  do {
    printf (
      "make your choice (enqueue (e), dequeue (d), traveral (t),"
      " f (fine)): ");
    scanf ("%s", choice);
   
    if (strcmp (choice, "e") == 0) {
      read (&val);
      pTail = enqueue (pTail, val);
    } else
      if (strcmp (choice, "d") == 0) {
	pTail = dequeue (pTail, &val, &status);
        write (val, status);
      } else {
        if (strcmp (choice, "t") == 0) {
	  traversal (pTail);
	} else {
          if (strcmp (choice, "f") != 0) {
            printf ("Wrong Choice.\n");
          }
        }
      }
  } while (strcmp (choice, "f") != 0);

  return (SUCCESS);
}

struct e *
enqueue (
  struct e *pTail,
  int val
  )
{
  struct e *pNew;

  pNew = newE ();

  pNew->key = val;

  if (pTail==NULL) {
    pTail = pNew;
    pTail->next = pTail;
 } else {
    pNew->next = pTail->next;
    pTail->next = pNew;
    pTail = pNew;
  }

  return (pTail);
}

struct e *
dequeue (
  struct e *pTail,
  int *val,
  int *status
  )
{
  struct e *pOld;

  if (pTail != NULL) {
    *status = SUCCESS;
    if (pTail == pTail->next) {
      *val = pTail->key;
      free (pTail);
      pTail = NULL;
    } else {
      pOld = pTail->next;
      *val = pOld->key;
      pTail->next = pOld->next;
      free (pOld);
    }
  } else {
    *status = FAILURE;
  }

  return (pTail);
}

void
traversal (
  struct e *pTail
  )
{
  struct e *pTmp;

  fprintf (stdout, "pTail -> ");
  if (pTail == NULL) {
    fprintf (stdout, "NULL\n");
  } else {
    pTmp = pTail;
    do {
      fprintf (stdout, "%d -> ", pTmp->key);
      pTmp = pTmp->next;
    } while (pTmp != pTail);

    fprintf (stdout, "pTail \n");
  }

  return;
}

struct e *
newE (
  )
{
  struct e *p;

  p = (struct e *) malloc (sizeof (struct e));

  if (p==NULL) {
    fprintf (stderr, "Allocazione fallita.");
    exit(EXIT_FAILURE);
  }

  return (p);
}

void
read (
  int *val
  )
{
  fprintf (stdout, "Element: ");
  scanf ("%d", val);

  return;
}

void
write (
  int val,
  int status
  )
{
  if (status == SUCCESS) {
    fprintf (stdout, "Element: %d\n", val);
  } else {
    fprintf (stdout, "Empty Queue.\n");
  }

  return;
}



