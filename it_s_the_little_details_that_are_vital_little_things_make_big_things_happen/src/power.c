int power(int x, int y)
{
  if (y < 0) 
  	return -1;
  if (y == 0)
  	return 1; 
  if (y == 1)
  	return x;
  if ((x * power(x, y-1)) > 2147483647)
  	return -1;
  return(x * power(x, y-1));
}
