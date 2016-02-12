#include "my_functions.h"

void print_combination_1(void)         
{
for (int u = 0; u < 10; u++) { /* loop for digit */
  print_number(u); /* print number */
  if (u < 9) {
  print_char(','); /* add comma and space but not for the last digit*/
  print_char(' ');
}
}
}
