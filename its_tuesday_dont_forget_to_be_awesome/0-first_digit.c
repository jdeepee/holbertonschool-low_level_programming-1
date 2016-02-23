int first_digit(int n)         
{
  long int u = n;
  if (u < 0) {
  u = u * -1; /* If less than 0 multiply times -1 to get positive. */
  }
  while(u >= 10){
      u /= 10;
  }
  return u;
}
