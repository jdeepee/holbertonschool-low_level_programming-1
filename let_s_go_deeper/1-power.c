int power(int x, int y)
{
  if (y < 0) 
  	return -1;
  if (y == 0)
  	return 1; /* power of a number to 0 is one */
  if (x < 0)
  	return -1; 
  if (y == 1)
  	return x;
  if ((x * power(x, y-1)) > 2147483647) /* is it more than max int */
  	return -1;
  return(x * power(x, y-1)); /*recursion */
}
