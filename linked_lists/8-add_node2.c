#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int strlength(char *str) { /* get length of string */
  int count = 0;
  while (str[count] != 0) {
    count++;
  }
  return (count + 1);
}

void copy_str(char *src, char *dest) { /* function to copy a string */
  char *hold;
  
  while (*src != 0) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = 0; /* reset */

  hold  = src;
  hold = dest;
  src = hold + 1;
}

int add_node(List **list, char *str) { /* function adds node at the end of the list */
  List *node_to_add = malloc(sizeof(List));
  List *curr = *list;

  node_to_add->next = NULL;
  node_to_add->str = malloc(sizeof(char) * strlength(str));
  copy_str(str, node_to_add->str); /*add to end of list */

  if (node_to_add == NULL) {
    return 1; /* failed */
  }

  if (curr == NULL) {
    *list = node_to_add;
    return 0; 
  }

  while (curr->next != NULL) curr = curr->next;
  curr->next = node_to_add;

  return 0;
}
