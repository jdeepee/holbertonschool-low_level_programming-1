#include <stdio.h>

void print_combination_2(void)         
{
int u,o;
for (u = 0; u < 10; u++) { /* loop for first digit */
	for (o = 0; o < 10; o++) { /* loop for second digit */
		if (o >= u ) {
			if (u != o) {
				printf("%d", u);
				printf("%d", o);

			if (u == 8 && o == 9) {
			} else {
				printf(",");  /* add comma and space but only if the number isn't 89 */
				printf(" ");
			}
  			
  		}
		}
	}
}

}
