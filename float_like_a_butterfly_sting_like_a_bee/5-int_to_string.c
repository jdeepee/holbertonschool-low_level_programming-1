#include <stdlib.h>

int getlength(long hvalue){
  int countlength=1;
  while(hvalue>9)
    {
      countlength++;
      hvalue/=10;
    }
  return countlength; /*Return the length of a long */
}

int powerof(int x, int y)
{
	if( y == 0) {
		return 1;
	}
	else if (y%2 == 0) {
		return(powerof(x, y/2)*powerof(x, y/2));  /* recursion */
	}
	else {
		return(x*powerof(x, y/2)*powerof(x, y/2));  /* recursion */
	}
}

char *int_to_string(int x)
{
	int tlen = 0, i = 0, pos = 0, flag = 0;
	char *ret; long numb = x, temp = 0;  
	if ( numb < 0 ) {
		numb = numb * -1;
		flag = 1;
	}
	tlen = getlength(numb);
	ret = flag ? malloc(sizeof( *ret ) * (tlen + 1)): malloc(sizeof( *ret ) * tlen);
	if (ret == NULL) {
		return (NULL);
	} else {
		if(flag)
		{
			ret[pos]='-';
			pos++;
		}      
		for(i = tlen -1; i >= 0; i--, pos++)
		{
			temp = numb / powerof(10, i);
			ret[pos] = temp + 48;
			numb = numb - temp * powerof(10, i); 
		}}
	return ret; 
}

