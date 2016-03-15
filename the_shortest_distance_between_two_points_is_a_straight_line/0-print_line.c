int print_char(char c);

void print_line(int n)
{
  int i = 1;
  for (; i <= n; i++) {
    print_char('_');
  }
  print_char('\n');
}
