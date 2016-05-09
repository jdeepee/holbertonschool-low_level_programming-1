#include "list.h"
#include <stdlib.h>

void rev_list(List **list) { /* function that reverses the order of the nodes in the list */
  List *slow = *list;
  List *next;
  List *base;

  next = slow->next; /* store */
  slow->next = NULL;
 
  while (next != NULL) { /* add to next */
    base = next;
    next = base->next;
    base->next = slow;
    slow = base;
  }
  *list = slow; 

}
