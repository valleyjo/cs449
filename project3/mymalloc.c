/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>

void *my_next_fit_malloc(int size){

  void *ptr;
  ptr = sbrk(0);

  if (sbrk(size) == (void*)-1)
    return NULL;
  else
    return ptr;
}

void my_free(int *ptr){

}
