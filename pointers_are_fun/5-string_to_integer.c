int string_to_integer(char *s){
	int count = 0;
	int tot;
	int c;
	int ac;
	int posit = 1;
	long numb = 0;
	while (	*(s+count) != '\0' ){	
		c = *(s+count)+0;
		ac = *(s+count+1)+0; /*ac is the next value. So we know when to stop */
		if( c > 47 && c < 58){
			tot = c - '0'; 
			numb =  numb + tot; 
			if( (numb > 2147483647 && posit == 1 ) || (numb > 2147483648  && posit == -1 ) ){
				return 0; /* Too big or small */
			}
			if( ac < 47 || ac > 58){
				break; //Not a number
			}
			numb *= 10;
		}
		if( c == 45  ){ /*Check if the current char is a symbol indicating if it's negative.*/
			posit *=(-1);
		}	
		count +=1;	
	}
	return(numb*posit); 
}
