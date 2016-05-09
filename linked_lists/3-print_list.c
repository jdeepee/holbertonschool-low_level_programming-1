#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int print_char(char);

void print_string(char *str) { /* print a pointer */
  while (*str != 0) {
    print_char(*str);
    str++;
  }
}

void print_list(List *list) {
  int hold = 1;

  if (list == NULL) {
    print_char('\n');
    return; /* nothing */
  }

  do {
    if (!hold) {
      print_char(',');
      print_char(' ');
    } else {
      hold = 0;
    }
    print_string(list->str); /* print */
    list = list->next;
  } while (list != NULL);
  print_char('\n');
}

