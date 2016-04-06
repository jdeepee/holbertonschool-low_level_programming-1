void array_iterator(int *array, int size, void (*action_func)(int)) {
	int count = 0;
	for (; count<size; count++) {
		action_func(array[count]);
	}
}
