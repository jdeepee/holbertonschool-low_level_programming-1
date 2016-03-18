char *rot13(char *h){
	int i = 0;
	while(*h)
	{
		if ((*h >= 'a' && *h <= 'm') || (*h >= 'A' && *h <= 'M')) {
			*h = *h + 13; /*Rotates 13 places */
		} else if ((*h >= 'n' && *h <= 'z') || (*h >= 'N' && *h <= 'Z')) {
			*h = *h - 13; /*Rotates 13 places */
		}
		i++;
        h++;
    }
	return &(h[-i]);
}
