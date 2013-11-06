/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>
#include "mymalloc.c"

int main(){
  int *init_adr;
  int *old_adr;
  int *top_adr;

  printf("Unit testing your custom malloc...\n");
  init_adr = sbrk(0);
  printf("Initial Address location: %d\n\n", init_adr);

  old_adr = my_next_fit_malloc(20);

  if (*old_adr != *init_adr){
    printf("ERROR. Expected initial address and return address\
            after the first allocation to be equal");
    printf("Initial address: %d", init_adr);
    printf("Returned Address: %d", old_adr);
  }

  top_adr = sbrk(0);
  printf("Address after allocation of 20 bytes: %d\n\n",\
          top_adr);

  return 0;
}
