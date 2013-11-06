/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>

int main(){
  int *adr;

  printf("Unit testing your custom malloc...\n");
  adr = sbrk(0);
  printf("Initial Address location: %d\n", adr);

  return 0;
}
