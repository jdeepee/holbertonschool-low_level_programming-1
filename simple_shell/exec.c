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

int exe_child(char **command, char **env){
  int status;
  char *path;

  if (command[0][0] != '/' ) {
    path = get_path(env,command[0]);
  } else {
    path = command[0];
  }
  status = execve(path, command, env);
  if (status == -1){ /* does program exist */
    print_string("-cisfun: ");
    print_string(command[0]);
    print_string(": command not found\n");
    free_command(command);
    free(path);
    return status;
  } else {
    free(path);
    free_command(command);
    return 0;
  }
}

int exe_father(char **env, char **command, int status, char *line){
  if (strings_compare(command[0], "exit") == 0) {
    free(line);
    free_command(command);
    exit_shell(command);
  } else if (strings_compare(command[0], "$?") == 0) {
    print_number(status);
    print_string("\n"); 
    return 1;
  } else if (strings_compare(command[0], "env") == 0){
    print_env(env);
    return 1;
  } else if (strings_compare(command[0], "setenv") == 0){
    do_setenv(command);
    return 1;
  } else if (strings_compare(command[0], "unsetenv") == 0){
    do_unsetenv(command);
    return 1;
  }
  return 0;
}