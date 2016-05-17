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

char *concat_strings(char *s1, char *s2)
{
	int len,len2,i,j;
	char *s;

	i = 0;
	j=0;
	len = str_len(s1);
	len2= str_len(s2);  
	s = malloc(sizeof(*s) * (len + len2 + 1) );

	if (s == NULL) {
		return ( NULL);
	} else {
		while(i < len){
			s[i]= s1[i];
			i++;
		} while(j < len2) {
			s[i] = s2[j];
			i++;
			j++;
		}
		s[i] = '\0';
	}
	return s; 
}