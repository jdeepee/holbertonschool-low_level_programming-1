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

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env) {
  char **command;
  char *line;
  int status;
  pid_t pid;
  char *path;
  int i;

  while (1) {
    write(1, "shellisfun$:", 12); /* Print Prompt */
    line = read_line(0);
    command = string_split(line, ' ');

    if (str_len(line) < 1){
    } else {
      if (strings_compare(command[0], "exit") == 0) {
        free(line);
        free_command(command);
        exit_shell(command);
      } else if (strings_compare(command[0], "$?") == 0) {
        print_number(status);
        print_string("\n"); 
      } else if (strings_compare(command[0], "env") == 0){
          for(i=0; env[i] != NULL; i++){
            print_string(env[i]);
            print_string("\n");
          }
      } else if (strings_compare(command[0], "setenv") == 0){
        if (command[1] && command[2]){
          if (setenv(command[1], command[2], 1) == 0){
            print_string("New variable was created\n");
          } else {
            print_string("A error occured when creating the variable\n");
          }
        } else {
          print_string("You are missing parameters for setenv\n");
        }
        free_command(command);
      } else if (strings_compare(command[0], "unsetenv") == 0){
        if (unsetenv(command[0]) == 0){
          print_string("Variable was successfully removed\n");
        } else {
          print_string("Error occured when removing variable\n");
        }
          free_command(command);  
      } else {
        pid = fork(); /* Create a fork */

        if (pid == -1) {
          write(2, "Fork failed!", 12); /* something went wrong */
        } else if (pid == 0) {
          if (command[0][0] != '/' ) {
            path = get_path(env,command[0]);
          } else {
            path = command[0];
          }
          if (execve(path,command,env) == -1){ /* does program exist */
            print_string("shellisfun$: '");
            print_string(command[0]);
            print_string("' was not found.\n");
            free(line);
            free_command(command);
            free(path);
            return 1;
          } else {
            free(path);
            free_command(command);
            free(line);
          }
        } else {
          wait(&status);
        }
          free_command(command);
          free(line);
        }
      }
    }
}

void exit_shell(char **command) {
  int value;
  write(2, "Goodbye cruel world...\n", 23); /* exiting */
  if (len_command(command) <= 1) {/* If there is no value return 0; */
    exit(0);
  }
  value = string_to_integer(command[1]);
  exit(value); /* exit with value */
}

char *get_path(char **env , char *cmd)
{
  char **paths, **paths2;
  char *path;
  char *p;
  int i;
  for (i = 0; env[i]!= NULL; i++){ /* loop for each PATH */
    if(str_ncomp(env[i], "PATH=", str_len("PATH=")) == 0) 
      {
        paths = string_split(env[i],'=');
        path = paths[1];
        paths2 = string_split(path, ':');
        break; /* Get the path */
      }   
  }  
  free_path(paths);
  for(i = 0; paths2[i] != NULL; i++) {
      p = concat_strings(paths2[i], "/");
      path = concat_strings(p,cmd);
      if(find_ex(path)){
        free(p);
        break;
      } else {
        path = '\0';
      }
      free(p);
      free(path);
   } 
   free_path(paths2);
   return path;
}

void free_path(char **paths) { /* free */
  int i = 0;
  while (paths[i] != 0) {
    free(paths[i]); /* free */
    i++; 
  }
  free(paths);
}

int find_ex(char *s) /* does program exist? */
{
  struct stat file_ex;
  
  if (lstat(s, &file_ex) == -1) 
    {
      return (0);
    } else {
    return(1);
  }
}

int getlength(char *str) {
  int total = 0; 
  while (*str != 0) {
    total++;
    str++;
  }
  return total; /* return length of string */
}

char *concat_strings(char *s1, char *s2) {

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

int string_to_integer(char *s){
    int count = 0;
    int total;
    int c;
    int nc;
    int l = 1;
    long on = 0;
    while (s[count] != '\0'){
        c = s[count]+0;
        nc = s[count+1]+0;
        if (s[count] == 45){
            l*=-1;
        } 
        if (c > 47 && c < 58){
            total = c - '0';
            on = on + total;
            if ( (on > 2147483647 && l == 1 ) || (on > 2147483648  && l == -1 )){
                return (0);
            }
            if( nc < 47 || nc > 58){
                break; /* Not a number */
            }
            on *= 10;
        }
        count+=1;
    }
    return(on*l);
}


int len_command(char **command) {
  int length = 0;
  while (*command != 0) {
    length++;
    command++;
  }
  return length; /* length of command */
}

int strings_compare(char *s1, const char *s2) 
{
  while(*s1 ==*s2++)
    if(*s1++ == 0)
      return 0; /* not the same */ 
  return (*(const unsigned char *)s1 - *(unsigned char *)(s2-1)); /* returns 1 */
}

void free_command(char **command) { /* free */
  int i = 0;
  while (command[i] != 0) {
    free(command[i]); /* free */
    i++; 
  }
  free(command);
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

int str_len(const char *str)
{
  int total = 0; 
  while (*str != 0) {
    total++;
      str++;
    }
    return total; /* return length of string */
}

int str_ncomp(char *s1, char *s2, int c)
{
  int i,first,second,t,n;
  i = 0;
  t = 0;  
  first=str_len(s1);
  second=str_len(s2);
  n = (first >= second) ? first : second;
  n = (c > n) ? n : c;
  while(i<n)
  {
    if(s1[i]!=s2[i]) /*compare strings */
    {
      t=s1[i]-s2[i]; 
      break;
    }
    else{
      t=0;
    }
    i++;
  }
  return (t);

}
