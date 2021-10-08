#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* structure declaration */
typedef struct node_s {
  int val;
  struct node_s *next;
} node_t;

/* function prototypes */
int read (void);
node_t *insert (node_t *head, int val);
void search (node_t *head, int val);
node_t *delete_first (node_t *head);
node_t *delete_last (node_t *head);
node_t *delete (node_t *head, int val);
void display (node_t *head);

/* 
 *  main program
 */
int main(void) {
  node_t *head=NULL;
  int val, stop=0;
  char choice;

  while (stop == 0) {
    fprintf(stdout, "\nAvailable commands:\n");
    fprintf(stdout, "  i: insert a value (sorted)\n");
    fprintf(stdout, "  s: search a value\n");
    fprintf(stdout, "  f: delete the first value\n");
    fprintf(stdout, "  l: delete the last value\n");
    fprintf(stdout, "  d: delete a specified value\n");
    fprintf(stdout, "  c: display the list contents\n");
    fprintf(stdout, "  e: end program\n");
    fprintf(stdout, "Make your choice: ");
    scanf("%c%*c", &choice);

    switch (choice) {
      case 'i': val = read();
                head = insert(head, val);
                break;
      case 's': val = read();
                search(head, val);
                break; 
      case 'f': head = delete_first(head);
                break;
      case 'l': head = delete_last(head);
                break;
      case 'd': val = read();
                head = delete(head, val);
                break;
      case 'c': display(head);
                break;
      case 'e': fprintf(stdout, "End of session.\n");
                stop = 1;
                break;
      default : fprintf(stdout, "Wrong choice!\n");
                break;
    }
  }

  return EXIT_SUCCESS;
}

/*
 *  read in a value
 */
int read (void) {
  int val;

  fprintf(stdout, "Value: ");
  scanf("%d%*c", &val);

  return val;
}

/*
 *  insert a value in the list (sorted)
 */
node_t *insert (node_t *head, int val) {
  node_t *p, *q=head;

  p = (node_t *)malloc(sizeof(node_t));
  p->val = val;
  p->next = NULL;

  /* insert ahead */
  if (head==NULL || val<head->val) {
    p->next = head;
    return p;
  }

  /* 
   *  scan the list with the q pointer in order to find 
   *  the correct position where to perform the insertion
   */
  while (q->next!=NULL && q->next->val<val) {
    q = q->next;
  }
  p->next = q->next;
  q->next = p;
  return head;
}

/*
 *  search a value in the list
 */
void search (node_t *head, int val) {
  node_t *p;
  int i;

  for (p=head, i=0; p!=NULL && p->val<val; p=p->next, i++) ;

  if (p!=NULL && p->val==val) {
    fprintf(stderr, "Element found (index = %d)\n", i);
  } else {
    fprintf(stderr, "Element NOT found.\n");
  }
}

/*
 *  delete the first element of the list
 */
node_t *delete_first (node_t *head) {
  node_t *p;

  /* empty list */
  if (head != NULL) {
    p = head->next;
    free(head);
    return p;
  }

  return head;
}

/*
 *  delete a list element, keeping it sorted
 */
node_t *delete_last (node_t *head) {
  node_t *p, *q=head;

  /* empty list */
  if (head == NULL) {
    fprintf(stderr, "Error: empty list\n");
    return NULL;
  }

  /* delete ahead */
  if (head->next == NULL) {
    free(head);
    return NULL;
  }

  /* scan the list with the q pointer */
  while (q->next->next!=NULL) {
    q = q->next;
  }
  p = q->next;
  q->next = NULL;
  free(p);

  return head;
}

/*
 *  delete a list element, keeping it sorted
 */
node_t *delete (node_t *head, int val) {
  node_t *p, *q=head;

  /* empty list */
  if (head == NULL) {
    fprintf(stderr, "Error: empty list\n");
    return NULL;
  }

  /* delete ahead */
  if (val == head->val) {
    p = head->next;
    free(head);
    return p;
  }

  /* 
   *  scan the list with the q pointer in order to find 
   *  the element to remove from the list
   */
  while (q->next!=NULL && q->next->val<val) {
    q = q->next;
  }
  if (q->next!=NULL && q->next->val==val) {
    p = q->next;
    q->next = p->next;
    free(p);
  } else {
    fprintf(stderr, "Element NOT found.\n");
  }

  return head;
}

/*
 *  display the list contents
 */
void display (node_t *head) {
  int i=0;

  while (head != NULL) {
    fprintf(stderr, "Element %d = %d\n", i++, head->val);
    head = head->next;
  }
}
