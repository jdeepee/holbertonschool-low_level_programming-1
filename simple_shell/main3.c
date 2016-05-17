#include <unistd.h>
#include <stdlib.h>
#include "libshell/libshell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

void free_command(char **command);
void exit_shell(char **command);
int len_command(char **command);
int strings_compare(char *s1, const char *s2);
int string_to_integer(char *s);
int find_ex(char *s);
char *get_path(char **env, char *cmd);
void print_number(int);
int print_char(char);
void print_string(char *str);
char *concat_strings(char *s1, char *s2);
int str_ncomp(char *s1, char *s2, int c);
int str_len(const char *s);
void free_path(char **paths);
int getlength(char *str);
int exe_father(char **env, char **command, int status, char *line);
void print_env(char **env);
void do_setenv(char **command);
void do_unsetenv(char **command);
int exe_child(char **command, char **env);

void print_env(char **env){
  int i;

  for(i=0; env[i] != NULL; i++){
    print_string(env[i]);
    print_string("\n");
  }
}

void free_path(char **paths) { /* free */
  int i = 0;
  while (paths[i] != 0) {
    free(paths[i]); /* free */
    i++; 
  }
  free(paths);
}

void print_string(char *str){ /* Print a string */
  print_char(str[0]);
  while (*str != '\0'){
    str++;
    print_char(*str);
  }
}

int print_char(char c) /* Print a char */
{
  return (write(1, &c, 1));
}

void print_number(int n)         
{
  int v,t,d,i,u;
  char p;
  if (n == 0) {
    print_char('0'); /* Print '0' id n = 0. */
  }
  else
  {
    if (n < 0) {
    print_char('-'); /* negative numbers need a '-' first. */
    }
    n = (((n<=0)-(n>0)) * n); /* We need n to be an absolute number (always positive) */
     for (t = 0, v = n; v<=-1; t++) 
      v /= 10;  /* make v = n and then / by 10 until < -1 */
      for (u = t; u > 0; u--) /* for each digit loop once*/
      {
        for (i=1, d=-1; u>i; i++) /* loop to figure out what to divide by */
        d *= 10; /* Multiply X 10 */
        p = ((n-(n%d))/d); /* This is how the first digit is determined */
        print_char('0' + p); /* Print */
        n -= (p * d); /* Remove the digit we printed from n */
      }
  }
}