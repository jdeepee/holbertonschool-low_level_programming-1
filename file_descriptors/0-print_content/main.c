#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **argv) {/* get the number of arguments and the arguments */
  int file;
  char buffer;

  if (ac != 2) {
    return (1); /* not enough args */
  }

  file = open(argv[1], O_RDONLY);
  while(read(file, &buffer, 1)) {
    write(1, &buffer, 1);
  }

  if(close(file)){
    return (1); /* SOMETHING WENT  WRONG */
  }
  
  return(0);
}
