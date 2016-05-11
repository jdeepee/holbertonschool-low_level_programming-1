#include <fcntl.h>
#include <unistd.h>


int main(int ac, char **argv) { /* copies the content of a file into another file */
  int source, dest;
  char c;

  if (ac != 3) {
    return (1); /* three arguments expected */
  } else if((source = open(argv[1], O_RDONLY)) < 0) {
    return (1); /* three arguments expected */
  }

  dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644); /*open with premissions */
  while(read(source, &c, 1)) {
    write(dest, &c, 1);
  }

  if (close(source) || close(dest)) {
    return (1); /* error */
  }
  return (0);
}

