#include "my_functions.h"

void print_combination_2(void)         
{
for (int u = 0; u < 10; u++) { /* loop for first digit */
	for (int o = 0; o < 10; o++) { /* loop for second digit */
		if (o >= u ) {
			if (u != o) {
			print_number(u);
			print_number(o);
			
			if (u == 8 && o == 9) {
			} else {
			print_char(','); /* add comma and space but only if the number isn't 89 */
  			print_char(' ');	
			}
  			
  		}
		}
	}
}

}
