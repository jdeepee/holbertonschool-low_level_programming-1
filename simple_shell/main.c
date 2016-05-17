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

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **env) {
  char **command, *line;
  int status, f;
  pid_t pid;

  while (1) {
    write(1, "shellisfun$:", 12); /* Print Prompt */
    line = read_line(0);
    command = string_split(line, ' ');
    if (str_len(line) < 1){
    } else {
      f = exe_father(env, command, status, line);
      if (f == 1){
      } else if (f == 0) {
        pid = fork(); /* Create a fork */
        if (pid == -1) {
          write(2, "Fork failed!", 12); /* something went wrong */
        } else if (pid == 0) {
          return exe_child(command, env);
        } else {
          wait(&status);
        }
          free_command(command);
          free(line);
        }
      }
    }
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
