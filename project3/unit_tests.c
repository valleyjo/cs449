/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>
#include "mymalloc.c"

void test1();
void test2();
void test3();

int main(int argc, char *argv[]){
  int *adr;
  char input;

  printf("Unit testing your custom malloc...\n");
  adr = sbrk(0);
  printf("Initial Address location: %d\n", adr);

  test2();

  return 0;
}


void test1(){
  printf("\ntest case #1");

  int *malloc1 = my_next_fit_malloc(100);
  int *malloc2 = my_next_fit_malloc(50);
  int *malloc3 = my_next_fit_malloc(75);

  printf("\nmalloc1: %d:", malloc1);
  printf("\nmalloc2: %d:", malloc2);
  printf("\nmalloc3: %d:", malloc3);

  print_list();
}

void test2(){

  printf("\ntest case #2");

  int *malloc4 = my_next_fit_malloc(100);
  int *malloc5 = my_next_fit_malloc(50);
  int *malloc6 = my_next_fit_malloc(75);

  printf("\nmalloc1: %d:", malloc4);
  printf("\nmalloc2: %d:", malloc5);
  printf("\nmalloc3: %d:", malloc6);

  my_free(malloc5);

  print_list();
}

void test3(){

}

