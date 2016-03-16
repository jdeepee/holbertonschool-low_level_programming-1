char *uppercase_string(char *h){
	int count = 0;

	 while(*h)
   {
       if ( *h >= 'a' && *h <= 'z' )
       {
          *h = *h - 32;
       }
       h++;
       count++;
   }
	return &(h[-count]);
}
