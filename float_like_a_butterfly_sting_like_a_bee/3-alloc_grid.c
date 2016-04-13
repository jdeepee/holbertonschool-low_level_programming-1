#include <stdlib.h>
int **alloc_grid(int width, int height) {
  int **arrgrid = malloc(sizeof(int *) * height);
  int i = 0;
  if (arrgrid == NULL) return NULL; /* failed to assign the memory */
  
  for ( ; i<width ; i++) {
    arrgrid[i] = malloc(sizeof(int) * width);
    if (arrgrid[i] == NULL) return NULL; /* failed to assign the memory */
  }

  return arrgrid;
}
