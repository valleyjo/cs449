#include <stdio.h>
#include <stdlib.h>

int isPrime(int num){
  int i;

  if (num <= 1)
    return 0;

  for (i = 1; i *i <= num; i++)
    if (num % i == 0)
      return 0;
  
  return 1;
}

int main(int argc, char *argv[] ){ 

  if (argc < 1 || argc > 2){
    printf("usage ./Prime 55");
    printf("\nWhere 55 is replaced by the integer in question.");
    exit(0);
  }
  
  int input = atoi(argv[1]);
  int prime = isPrime(input);

  if (prime)
    printf("%d is prime!\n\n",input);

  else
    printf("%d is not prime!\n\n", input);
}
