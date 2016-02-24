#include "my_functions.h"

void print_alphabet(void)
{
  int i; /* creates interger 'i' */
	for (i = 97; i < 123; i++)  /* A for statment to look through ascii char values */
    {
      print_char(i); /* if it fits our parameters from the for statment we print it out. */
    }
}
