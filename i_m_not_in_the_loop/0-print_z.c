#include "my_functions.h"

int print_number(int n)
{
  return (write(1, &n, 1));
}
