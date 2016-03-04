int print_char(char c);

void reverse_string(char *s)
{
	char d[10];
	d[0] = s[8];
	d[1] = s[7];
	d[2] = s[6];
	d[3] = s[5];
	d[4] = s[4];
	d[5] = s[3];
	d[6] = s[2];
	d[7] = s[1];
	d[8] = s[0];
	s[0] = d[0];
	s[1] = d[1];
	s[2] = d[2];
	s[3] = d[3];
	s[4] = d[4];
	s[5] = d[5];
	s[6] = d[6];
	s[7] = d[7];
	s[8] = d[8];
}
