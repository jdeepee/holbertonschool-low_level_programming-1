char *string_ncopy(char *dest, const char *src, int n)
{
	int count = 0;
	while (count < n) {
		*dest = *src;
		src++;
		dest++;
		count++;
	}
	return &(dest[-count]);
}
