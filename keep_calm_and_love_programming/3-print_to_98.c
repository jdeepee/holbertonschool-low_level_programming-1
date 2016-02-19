#include <stdio.h>
void print_to_98(int n)         
{
	int i;
	if (n>98) { /* Need to count down */
  		for(i = n; i > 98; i--) {
  			printf("%d, ", i);
		}
	} else { /* Need to count up */
  		for(i = n; i < 98; i++) {
  			printf("%d, ", i);
		}
	}
	if (i == 98) {
				printf("98\n"); /* needs to end with '98' and a new line */
	}

}
