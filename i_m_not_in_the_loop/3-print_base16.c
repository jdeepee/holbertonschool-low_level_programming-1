#include "my_functions.h"

void print_base16(void)
{
  int i; /*make i an int*/

  for (i = 48; i < 58; i++)  /* for statement to look through 0-9 ascii values */
    {
      print_char(i);/* if the value of i fits the for statement than print it */
    }

  for (i = 65; i < 71; i++)  /* for statement to look through A-F ascii values */
    {
      print_char(i); /* if the value of i fits the for statement than print it */
    }
}
