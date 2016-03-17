int print_char(char c);

void print_diagonal(int n)
{
  int column = 1;
  int level = 1;
  if (n <= 0) {
    print_char('\n');
  }
  for (level=1; level <=n; level++) {
    for (column=1; column <= n; column++) {
      if (column == level) {
        print_char('\\');
      }
      if (column < level) {
        print_char(' '); /* Correct number of spaces */
      }   
    }
    print_char('\n');
  }
}
