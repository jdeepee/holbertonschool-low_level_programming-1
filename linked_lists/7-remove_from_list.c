#include <stdlib.h>
#include "list.h"


void free_node(List *node) { /* free a node */
  free(node->str);
  free(node);
}

int list_size_3(List *list) { /* function that returns the number of node in a list */
  int count = 1;
  if (list == NULL) {
    return 0;
  }
  while (list->next != NULL) {
    list = list->next;
    count++;
  }
  return count;
}

void remove_from_list(List **list, int index) { /*  function that removes and frees a node from a list at a specific index */
  int pos = 0;
  List *ptr = *list; 
  List *tmp;

  if (index < 0) return;
  if (list_size_3(*list) <= index) return;
  if (index == 0) {
    *list = (*list)->next; /* for each */
    return;
  }

  while (pos < index-2) {
    pos++;
    ptr = ptr->next;
  }

  tmp = ptr->next->next;
  free_node(ptr->next); /* free each node */
  ptr->next = tmp;
}


