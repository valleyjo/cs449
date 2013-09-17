//Created By: Alex Vallejo
//Date: 9/13/2013
//Project: Rock, Paper, Scissors and EXIF Viewer
//Class: CS 447

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char who_won(char computer_choice, char player_choice){
  if (player_choice == computer_choice)
    return 't';

  if (computer_choice == 'r'){
    switch (player_choice){
      case 'p':
        return 'p';
      
      case 's':
       return 'c';
    }
  }  
  
  if (computer_choice == 'p'){
     switch (player_choice){
       
       case 'r':
        return 'c';
      
       case 's':
        return 'p';
    }
  }  
  
  if (computer_choice == 's'){
    switch (player_choice){

      case 'p':
       return 'c';
      
      case 'r':
       return 'p';
    }
  }  
}

int main(){
  char input[50];
  int computer_score = 0, player_score = 0;  
  char computer_choice, player_choice, winner;
  char full_computer_choice[10];
  char result_of_battle[10];  
 
  srand((unsigned int)time(NULL));
  
  printf("Welcome to Rock, Paper, Scissors\n");

  printf("\nWould you like to play? ");
  scanf("%s",&input);
  
  input[0] = tolower(input[0]);
  
  if (input[0] == 'n'){
    printf("\nThanks for playing!\n\n");
    return 0;
  }
  
  else if (input[0] != 'y'){
    printf("\nSorry, you have entered invalid input. Now Exiting...\n\n");
    return 0;
  }
  
   do {   
     printf("\nWhat is your choice? ");
     scanf("%s", &input);
      
     input[0] = tolower(input[0]);
      
     if (input[0] != 's' && input[0] != 'r' && input[0] != 'p'){
       printf("\nSorry, you can only enter rock, paper or scissors.\n");
       continue;
     }
    
     player_choice = input[0];
     computer_choice = rand() % 4;
        
     switch (computer_choice){
       case 0:
         computer_choice = 's';
         strcpy(full_computer_choice,"scissors");
         break;
         
       case 1:
         computer_choice = 'r';
         strcpy(full_computer_choice, "rock");
         break;
         
       default:
         computer_choice = 'p';
         strcpy(full_computer_choice,"paper");
     }
   
     winner = who_won(computer_choice, player_choice);

     if (winner == 'c'){
       computer_score++;
       strcpy(result_of_battle, "lose");       
     }

     else if (winner == 'p'){
       player_score++;  
       strcpy(result_of_battle, "win");       
     }

    else
      strcpy(result_of_battle, "tie");
    
    printf("The computer choses %s. You %s this game\n", 
           full_computer_choice, result_of_battle); 
    printf("\nThe score is now you: %d computer: %d\n", player_score, computer_score);

  } while (computer_score < 3 && player_score < 3);
}//end main
