
int shell_comp(char *s1, char *s2)
{
  if (*s1 == 0 || *s2 == 0) {
    if ((*s2 == 0 || *s2 == '*') && *s1 == 0) {
      return 1;
    }
    return 0;
  }
  if (*s2 == '*' ) {
    if (*(s2+1) != *s1) {
      return shell_comp(s1+1, s2);
    }
    if (shell_comp(s1, s2+1)){
      return 1;
    } else {
      return shell_comp(s1+1, s2);
    }
  }
  if (*s1 != *s2) 
    return 0;
  return shell_comp(s1+1, s2+1);
}
