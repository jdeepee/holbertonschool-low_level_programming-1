char *leet(char *h){

	int count = 0;
	while(*h)
	{
		if ( *h == 'A' || *h == 'a' )
			*h = '4';
		if ( *h == 'e' || *h == 'E' )
			*h = '3';
		if ( *h == 'o' || *h == 'O' )
			*h = '0';
		if ( *h == 't' || *h == 'T' )
			*h = '7';
		if ( *h == 'l' || *h == 'L' )
			*h = '1';
		h++;
		count++;
	}
	return &(h[-count]);
}
