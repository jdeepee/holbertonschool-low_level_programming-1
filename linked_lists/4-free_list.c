#include "list.h"
#include <stdlib.h>

void free_node(List *node) { /* free a node */
  free(node->str);
  free(node);
}

void free_list(List *list) { /*function that frees a list*/
  List *hold;
  while (list != NULL) { /* loop and free each */
    hold = list;
    list = list->next;
    free_node(hold);
  }
}


