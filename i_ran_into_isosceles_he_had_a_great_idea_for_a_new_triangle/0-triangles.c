#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void triangles_in_the_term(int h, int n) {
	if (n > 0 && h > 0) {
		int s, m, v, i;
		int t = 1;
		for (m = h; m > 1; m--){ /* Count the number of chars on the last row */
				t = (t + 2); 
		}
		for (s = n; s > 0; s--){ /* For each triangle */
			int c = 1;
			for (m = h; m > 0; m--){ /* For each level */
				v = (t - c)/2; /* get spaces before */
				for (i = v; i > 0; i--) {
					print_char(' '); /*print spaces*/
				}
				for (i = c; i > 0; i--) {
					print_char('*'); /* print a star */
				}
				c = (c + 2);
				print_char('\n');
			}
		}
	}
}
