#include <stdio.h>

int main(){
  printf("%-14s %5d bytes\n", "int", sizeof(int));
  printf("%-14s %5d bytes\n", "short",  sizeof(short));
  printf("%-14s %5d bytes\n", "short", sizeof(long));
  printf("%-14s %5d bytes\n", "long long", sizeof(long long));
  printf("%-14s %5d bytes\n", "unsigned int", sizeof(unsigned int));
  printf("%-14s %5d bytes\n", "char", sizeof(char));
  printf("%-14s %5d bytes\n", "float", sizeof(float));
  printf("%-14s %5d bytes\n", "double",  sizeof(double));
  printf("%-14s %5d bytes\n", "long double", sizeof(long double));
 
  return(0); 
}
