#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
  unsigned int output;
  int i = open("/dev/dice", O_RDONLY);
  int n = read(i, &output, sizeof(int));

  output = output % 6;

  printf("\n%d\n", output);

  return 1;
}
