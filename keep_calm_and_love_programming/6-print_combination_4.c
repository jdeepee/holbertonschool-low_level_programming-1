#include "my_functions.h"

void print_combination_4(void)         
{
	int u,o,p,a,s,d;
		for (u = 0; u < 10; u++) { /* loop for first digit */
			for (o = 0; o < 10; o++) { /* loop for second digit */
				for (p = 0; p < 10; p++) { /* loop for third digit */
					for (a = 0; a < 10; a++) { /* loop for 4th digit */
							s = u*10;
							s = s+o;
							d = p*10;
							d = d+a;
						if (s != d) { /* avoid duplicates */
							if (d > s) {
									print_number(u);
									print_number(o); /* print number */
									print_char(' ');	
									print_number(p);
									print_number(a);
									if (d == 99 && s == 98) {
									}else{
									print_char(','); /* add comma and space but only if the number isn't 98, 99 */
			  						print_char(' ');
			  					}
			  				}

						}

					}
				}
			}
		}
}
