char *concat_strings(char *dest, const char *src)
{
  int count = 0;
  while(*dest)
  {
    dest++;
    count++;
  }
  while(*src)
  {
    *dest = *src;
    src++;
    dest++;
    count++;
  }
  *dest = '\0';
  return &(dest[-count]);
}
