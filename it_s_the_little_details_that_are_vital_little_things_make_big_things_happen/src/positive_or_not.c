int print_char(char c);

void positive_or_not(int n)
{
  if (n > 0) /* is n greater than 0? */
    {
      print_char('P'); /* print 'P' for positive */
    }
  if (n < 0) /* is n less than 0? */
    {
      print_char('N'); /* print 'N' for negative */
    }
  if (n == 0) /* does n equal 0? */
    {
      print_char('Z'); /* print 'Z' for zero */
    }
}
