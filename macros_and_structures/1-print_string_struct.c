#include "str_struct.h"
#include <stdio.h>

void print_string_struct(struct String *str) /* Prints a string from a struct */
{
  printf("%s", str->str);
  printf(", ");
  printf("%d\n", str->length);
}
