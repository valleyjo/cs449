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

  if (argc < 2)
    input = 48;
  else
    input = *argv[1];

  //printf("\ntest case execuition selection: %c\n", input);

  switch (input){
    case '0':
      printf("\nexecuiting all tests\n");
      test1();
      test2();
      test3();
      break;

    case '1':
      test1();
      break;

    case '2':
      test2();
      break;

    case '3':
      test3();
      break;
  }
  return 0;
}


void test1(){
  printf("\n\ntest case #1");

  int *malloc1 = my_next_fit_malloc(20);
  int *malloc2 = my_next_fit_malloc(20);
  int *malloc3 = my_next_fit_malloc(20);

  printf("\nmalloc1: %d:", malloc1);
  printf("\nmalloc2: %d:", malloc2);
  printf("\nmalloc3: %d:", malloc3);

  print_list();
}

void test2(){

}

void test3(){

}

