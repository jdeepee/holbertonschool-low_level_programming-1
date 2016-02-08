#include "my_functions.h"

void print_tebahpla(void)
{
int i; // make i an int
for (i = 122; i > 96; i--) //for statment to go backwards through ascii values
    {
      print_char(i); // if the value of i fits the for statement than print it
    }
}
