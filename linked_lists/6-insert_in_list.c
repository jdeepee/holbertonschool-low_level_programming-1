#include <stdlib.h>
#include "list.h"

int strlength_2(char *str) { /* get length of string */
  int count = 0;
  while (str[count] != 0) {
    count++;
  }
  return (count + 1);
}

void copy_str_2(char *src, char *dest) { /* function to copy a string */
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

int add_node_2(List **list, char *str) { /* add node function */
  List *node_to_add = malloc(sizeof(List));
  List *curr = *list;

  node_to_add->next = curr;
  node_to_add->str = malloc(sizeof(char) * strlength_2(str));
  copy_str_2(str, node_to_add->str); /*add to start of list */

  if (node_to_add == NULL) {
    return 1; /* failed return 1 */
  }

  if (curr == NULL) {
    *list = node_to_add;
    return 0; 
  }

  *list = node_to_add;

  return 0;
}

int list_size_2(List *list) { /* function that returns the number of node in a list */
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


int insert_in_list(List **list, char *content, int index) { /*function that creates a node and then inserts it in a list at a specific index*/
  int pos = 0;
  List *ptr = *list;
  List *tmp;
  /* edge cases */
  if (index < 0) return 1;
  if (list_size_2(*list) <= index) return 1;
  if (index == 0) return add_node_2(list, content);


  while (pos < index-2) { /* started on first node, go back 2 */
    pos++; 
    ptr = ptr->next;
  }
  tmp = ptr->next;

  ptr->next = malloc(sizeof(List));
  if (ptr->next == NULL) return 1;

  ptr->next->next = tmp;

  ptr->next->str = malloc(sizeof(char) * strlength_2(content));
  copy_str_2(content, ptr->next->str);
  return 0;
}
