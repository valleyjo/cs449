
#include <stdio.h>
#include <unistd.h>

int main(){

  printf("Unit testing your custom malloc...\n");
  int *adr = sbrk(0);
  printf("Address location: %d", *adr);


}
