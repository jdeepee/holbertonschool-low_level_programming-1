
int advanced_search(int *array, int size, int (*check_func)(int)) {
	int count = 0;
	for (; count<size; count++) {
		if (check_func(array[count])==1) { 
			return(1); /* match found */
		}
	}
	return -1; /* No matches*/
}
