int print_char(char c);

void print_string_2(char *str)
{
	int a = 0;
	print_char(str[0]);
   	while (*str != '\0') {
    	str++;
    	a++;
    	  if(a%2==0) 
          { 
          	    	print_char(*str);
          }
   }
}
