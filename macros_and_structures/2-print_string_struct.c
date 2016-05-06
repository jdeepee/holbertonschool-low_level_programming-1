#include "str_struct.h"
#include <stdio.h>
int print_char(char);
void print_number(int);

void print_string_struct(struct String *str) /* Prints a string from a struct using it's stored length */
{
  int c=0; 

  while(c < str->length) {
    print_char(str->str[c]);
    c++;
  }

  print_char(',');
  print_char(' ');
  print_number(str -> length); /* Call Print number */
  print_char('\n');
}

void print_number(int n)
{
  /*declaring variables*/
  int ncopy=n;
  int power=1;
  int charint;
  /*what to do if 0 > ncopy*/
  if (0 > ncopy) {
    ncopy=ncopy*-1;
    print_char('-'); }
  /*finding the number of digits*/  
  for (; ncopy > 0;) {
    ncopy=ncopy/10;
    power=power*10; }
  power=power/10; 
  /*reinitializing the value of n*/
  if (0 > n) {
    n=n*-1; }
  /*printing out the numbers*/
  for (ncopy=n; ncopy > 0;) {
    charint=ncopy/power;
    ncopy=ncopy%power;
    power=power/10;
    print_char(charint + '0'); }
  /*what to if ncopy==0*/
  if (n == 0) {
    print_char('0');
  }
}
