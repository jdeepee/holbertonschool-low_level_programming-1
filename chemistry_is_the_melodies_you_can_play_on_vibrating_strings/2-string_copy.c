char *string_copy(char *dest, const char *src)
{
	int count = 0;
	while (*src) {
		*dest = *src;
		src++;
		dest++;
		count++;
	}
	*dest = '\0';
	return &(dest[-count]);
}
