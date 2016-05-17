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

void do_setenv(char **command){
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
}

void do_unsetenv(char **command){
  if (unsetenv(command[0]) == 0){
    print_string("Variable was successfully removed\n");
  } else {
    print_string("Error occured when removing variable\n");
  }
  free_command(command);  
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
