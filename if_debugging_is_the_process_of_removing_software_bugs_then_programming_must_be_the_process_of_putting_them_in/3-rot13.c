char *rot13(char *h){
	int i = 0;
	while(*h)
	{
		if ((*h >= 'a' && *h <= 'm') || (*h >= 'A' && *h <= 'M')) {
			*h = *h + 13;
		} else if ((*h >= 'n' && *h <= 'z') || (*h >= 'N' && *h <= 'Z')) {
			*h = *h - 13;
		}
		i++;
        h++;
    }
	return &(h[-i]);
}
