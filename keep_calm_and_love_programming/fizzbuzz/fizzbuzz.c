#include <stdio.h>

int main(void)
{
  int i;
  for (i = 1; i < 101; i++) { /* loop for 1 - 100 */
        if (!(i % 3)) {
          printf("Fizz"); /* by 3 */
        } else if (!(i % 5)) {
          printf("Buzz"); /* by 5 */
        } else {
          printf("%d", i); /* by nothing */
        }
        if (i != 100) {
         printf(" "); /* add spaces */
        } 
  }
  return (0);
}
