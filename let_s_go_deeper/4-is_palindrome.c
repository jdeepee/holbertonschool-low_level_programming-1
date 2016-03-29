

int str_len(char *str, int step)
{
  if (*(str+step) == 0) {
  	return step; /* Returns the len of the string using recursion */
  }
  return str_len(str, step+1);
}

/*
int str_len(char *str)
{
	int count = 0;
   while (*str != '\0') {
      count++;
      str++;
   }
   return count;
}
*/

int check_function(char *s, int step, int len)
{
  if (step >= len)
  	return 1; /* Is a palindrome */
  if (s[step] != s[(len-step)-1])
  	return 0; /* Not a palindrome */
  return check_function(s, step+1, len); /* loop for each */
}

int is_palindrome(char *s)
{
  int slen = str_len(s, 0); /* get the len of the string */
  return (check_function(s, 0, slen)); /* ([String], 0, [string_len]) */
}
