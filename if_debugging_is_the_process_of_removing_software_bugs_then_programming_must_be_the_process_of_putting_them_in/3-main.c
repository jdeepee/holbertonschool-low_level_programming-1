#include <stdio.h>
char *rot13(char *);

int main(void)
{
  char *p;
  char s[] = "Test output\nabcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

  p = rot13(s);
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  printf("------------------------------------\n");
  p = rot13(s);
  printf("------------------------------------\n");
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  p = rot13(s);
  printf("%s", p);
  printf("------------------------------------\n");
  printf("%s", s);
  printf("------------------------------------\n");
  return (0);
}
