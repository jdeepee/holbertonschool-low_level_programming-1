#include <stdlib.h>

void free_grid(int **grid, int height) {
  int count;
  for (count=0; count<height; count++) {
    free(grid[count]);
  }
  free(grid);
}
