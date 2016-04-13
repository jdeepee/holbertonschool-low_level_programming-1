#include <stdlib.h>

int getlength(char *str) {
  int total = 0; 
  while (*str != 0) {
    total++;
    str++;
  }
  return total; /* return length of string */
}

char *string_concat(char *s1, char *s2) {

  int tlen = getlength(s1) + getlength(s2);

  char *ret = malloc(sizeof(char)*(tlen+1));
  char *retc = ret;

  if (ret == NULL) return ret; /* Failed to allocate the memory. */

  while (*s1 != 0) {
    *retc = *s1;
    retc++;
    s1++; /* add the first part of the string */
  }

  while (*s2 != 0) {
    *retc = *s2;
    retc++;
    s2++; /* add the second part of the string */
  }

  *retc = 0;
  return ret;
}
