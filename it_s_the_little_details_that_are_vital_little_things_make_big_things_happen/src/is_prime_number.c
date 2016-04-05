
int loop_function(int n, int step) {
  if (n <= 1)
  	return 0; /* Not Prime */
  if (step > n/2)
  	return 1; /* Prime */
  if (n % step == 0)
  	return 0; /* Not Prime */
  return loop_function(n, step+1); /* Same as stepping through a for-loop but using a function */ 
}

int is_prime_number(int n)
{
  return loop_function(n, 2);
}
