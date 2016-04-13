#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);

void print_grid(int **a, int length, int height) {
  int rows, cols;
  for (rows=0 ; rows<length ; rows++) {
    for (cols=0 ; cols<height; cols++) {
      if (cols == (height-1)) {
      printf("%d ", a[rows][cols]);
      } else {
      printf("%d, ", a[rows][cols]);
      }
    }
    printf("\n");
  }
}

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = 402;
  print_grid(grid, 5, 5);
  return (0);
}
