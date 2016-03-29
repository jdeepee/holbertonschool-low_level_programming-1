#include <stdio.h>

int main(int argc, char *argv[])
 {
	int i = 0;
	if (!argv[1]) {
		printf("%d\n", i); /* print zero if the program has no args */
		return 0;
	}
	while (i < argc) {
		i++;
	}
	printf("%d\n", (i-1)); /* the first value in argv is the program name not an arg, subtract one */
	return 0;
 }
