char *cap_string(char *h){
	int count = 0;
	char prev = 0;
	while(*h)
	{
		if (prev == 0)
		{
			if ( *h >= 'a' && *h <= 'z' )
			{
				*h = *h - 32;
			}
		}
		prev = 1;
		if (*h == ' ') 
			prev = 0;
		h++;
		count++;
	}
	return &(h[-count]);
}
