void print_char(char c);

void print_last_digit(int n)         
{
	if (n<0){
		n=(n*-1); /* converts any negative numbers to positive */
	}
	n = n%10; /* get last digit */
	print_char('0' + n); /*print*/
}
