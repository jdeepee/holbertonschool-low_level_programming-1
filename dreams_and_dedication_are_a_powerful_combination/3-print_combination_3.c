#include "my_functions.h"

void print_combination_3(void)         
{
	for (int u = 0; u < 10; u++) { /* loop for first digit */
		for (int o = 0; o < 10; o++) { /* loop for second digit */
			for (int p = 0; p < 10; p++) { /* loop for third digit */
				if (o >= u) {
					if (p >= o) {
						if (u != o && o != p && p != u) {
							print_number(u);
							print_number(o); /* print number */
							print_number(p);
								if (u == 7 && o == 8 && p == 9) {
								} else {
									print_char(','); /* add comma and space but only if the number isn't 789 */
		  							print_char(' ');	
								}
	  					}
					}
	  			}
			}
		}
	}
}
