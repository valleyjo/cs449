#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

void my_strcpy(char *, char*);

int main(){

  char dest[100];
  char src[] = "Hello world";

  my_strcpy(dest, src);

  printf("%s\n", dest);

  return 0;
}
