#include "str_struct.h"
#include <stdlib.h>

struct String *string_to_struct(char *str) /* This function takes *str and it's length and stores is in a struct */
{
  struct String *string;
  int length = 0;
  
  if(str=='\0')
    return(0); /* Empty sting */

  while(str[length] != '\0')
    length++; /* get length */
  
  string = malloc(sizeof(struct String));

  if(string == NULL)
    return(NULL);
  
  string -> str = str; /* Store */
  string -> length = length;

  return(string);
}
