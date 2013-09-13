//Created By: Alex Vallejo
//Date: 9/13/2013
//Project: Rock, Paper, Scissors and EXIF Viewer
//Class: CS 447

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(){
  char input[5];
  int i;

  printf("Welcome to Rock, Paper, Scissors\n");

  printf("\nWould you like to play? ");
  scanf("%s",&input);
  
  input[0] = tolower(input[i]);
  
  if (input[0] == 'n'){
    printf("\nThanks for playing!\n\n");
    return 0;
  }
  
  else if(input[0] == 'y'){
    printf("\nWhat is your choice? ");
    scanf("%s", &input);
    printf("%s", input);
  }

  else{
    printf("\nSorry, you have entered invalid input. Now Exiting...\n\n");
    return 0;
  }

}
