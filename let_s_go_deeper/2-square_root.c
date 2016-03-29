
int loop_function(int n, int step) {
  if (step * step == n) 
  	return step; 
  if (step * step > n)
  	return -1; /* no square root */
  return loop_function(n, step+1); /* Same as stepping through a for-loop but using a function */ 
}

int square_root(int n) {
  return loop_function(n, 1);
}
