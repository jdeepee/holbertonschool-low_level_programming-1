#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **argv) { /* program that reproduces the behaviour of the cat command */
  int file;
  char hole;

  if(ac == 1) { /* only one arg */
    while(read(0, &hole, 1)) {
      write(1, &hole, 1);
    }
    return(0);
  } else if (ac == 2) {
    file = open(argv[1], O_RDONLY); /*open file */
    while(read(file, &hole, 1)) {
      write(1, &hole, 1); /* write output */
    }
    
    if(close(file)){
      return (1); /* error */
    }
  
    return(0);
  }
  
  return(1); /* error */
}



