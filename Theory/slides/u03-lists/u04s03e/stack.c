#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR    10

#define SUCCESS 1
#define FAILURE 0

struct e {
  int key;
  /* ... other data fields ... */
  struct e *next;
  };

struct e *push (struct e *pTop, int val);
struct e *pop (struct e *pTop, int *val, int *status);
struct e *newE (  );
void traversal (struct e *pTop);
void read (int *val);
void write (int val, int status);

int
main (
  void
  )
{
  char choice[MAX_STR];
  struct e *pTop;
  int val, status;

  pTop = NULL;

  do {
    printf (
      "User choice (push (p), pop (o), traveral (t), f (end)): ");
    scanf ("%s", choice);

    if (strcmp (choice, "p") == 0) {
      read (&val);
      pTop = push (pTop, val);
    } else
      if (strcmp (choice, "o") == 0) {
	pTop = pop (pTop, &val, &status);
	write (val, status);
      } else {
	if (strcmp (choice, "t") == 0) {
	  traversal (pTop);
	} else {
	  if (strcmp (choice, "e") != 0) {
	    printf ("Wrong Choice.\n");
	  }
	}
      }
  } while (strcmp (choice, "e") != 0);

  return (SUCCESS);
}

struct e *
push (
  struct e *pTop,
  int val
  )
{
  struct e *pNew;

  pNew = newE ();

  pNew->key = val;
  pNew->next = pTop;
  pTop = pNew;

  return (pTop);
}

struct e *
pop (
  struct e *pTop,
  int *val,
  int *status
  )
{
  struct e *pOld;

  if (pTop != NULL) {
    *status = SUCCESS;
    *val = pTop->key;
    pOld = pTop;
    pTop = pTop->next;
    free (pOld);
  } else {
    *status = FAILURE;
  }

  return (pTop);
}

void
traversal (
  struct e *pTop
  )
{
  struct e *pTmp;

  fprintf (stdout, "pTop -> ");
  pTmp = pTop;
  while (pTmp != NULL) {
    fprintf (stdout, "%d -> ", pTmp->key);
    pTmp = pTmp->next;
  }

  fprintf (stdout, "NULL \n");

  return;
}

struct e *
newE (
  )
{
  struct e *ePtr;

  ePtr = (struct e *) malloc (sizeof (struct e));

  if (ePtr==NULL) {
    fprintf (stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }

  return (ePtr);
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
    fprintf (stdout, "Empty stack.\n");
  }

  return;
}



