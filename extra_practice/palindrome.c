#include <stdio.h>
#include <string.h>

int main(){

  char input[50], rev[50];
  int i, length;

  printf("Enter a word: ");
  scanf("%s", &input);

  length = strlen(input) - 1;

  for (i = 0; i < length + 1; i++)
    rev[i] = input[length - i];

  if (0 == strcmp(rev, input))
    printf("\n%s is a palindrome\n", input);
  else
    printf("\n%s is not a palindrome\n", input);

  return 0;
}
