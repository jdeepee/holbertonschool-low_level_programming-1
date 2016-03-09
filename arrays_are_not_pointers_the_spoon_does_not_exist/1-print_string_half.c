int print_char(char c);

void print_string_half(char *str)
{
	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}
	str = str - count;
	if(count%2==0) {
		count = count / 2;
	} else {
		count = (count + 1) / 2;
	}
	int b = 0;
 	while (*str != '\0') {
    	str++;
    	b++;
		if(b >= count) 
		{ 
			print_char(*str);
		}
	}
}
