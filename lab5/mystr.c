#include <string.h>

void my_strcpy(char *dest, char *src){
  while (*dest++ = *src++);
}

void  my_strcat(char *dest, char *src){

  while(*dest++);
  dest--;
  my_strcpy(dest, src);
}
