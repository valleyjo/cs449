/* Username: amv49
 * Peoplesoft: 357811
 * Date: 11/15/2013
 * CS 449 Project 4
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DIE 5
#define DICE_ROLL rand() % 6 + 1;

void assign_categories(int *rolls, int *upper, int *lower){
  char input[20];
  int category_selection;

  printf("\nPlace dice into:\n");
  printf("1) Upper Section\n");
  printf("2) Lower Section\n");

  printf("\nSelection: ");
  fgets(input, sizeof(input), stdin);
  category_selection = atoi(input);

  // Upper categories
  if (category_selection == 1){
    printf("\nPlace dice into:\n");
    printf("1) Ones\n");
    printf("2) Twos\n");
    printf("3) Threes\n");
    printf("4) Fours\n");
    printf("5) Fives\n");
    printf("6) Sizes\n");

    printf("\nSelection: ");
    fgets(input, sizeof(input), stdin);
    category_selection = atoi(input);
  }

  // Lower categories
  else
    printf("Lower");
}

void reroll(int rolls[]){
  char input[NUM_DIE * 2], *token[NUM_DIE * 2];
  int i, reroll[NUM_DIE], num_rerolls = 0;

  // Initialize each reroll to false
  for(i = 0; i < NUM_DIE; i++)
    reroll[i] = 0;

  // get user input
  printf("\nWhich dice do you want to re-roll: ");
  fgets(input, sizeof(input), stdin);

  // parse the input and set reroll to true for any dice to be rerolled
  i = 0;
  token[0] = strtok(input, " ");
  while(token[i] != NULL){
    reroll[i] = 0;
    int dice_to_reroll = atoi(token[i]) - 1;
    reroll[dice_to_reroll] = 1;

    num_rerolls = i;
    i++;
    token[i] = strtok(NULL, " ");
  }

  // reroll each die if necessiary
  for(i = 0; i < NUM_DIE; i++)
    if(reroll[i] == 1)
      rolls[i] = DICE_ROLL

  // display the roll
  printf("\nYour reroll is:\n");
  for(i = 0; i < NUM_DIE; i++)
    printf("%d ", rolls[i]);
  printf("\n");

}

int main(){

  int turns, i, dice_to_reroll, rolls[NUM_DIE], upper[6], lower[7];
  char turns_msg[30], input[20];


  srand(time(NULL));

  for (turns = 13; turns >= 0; turns--){

    if (turns == 0)
      strcpy(turns_msg, "This is your last turn\n");

    else if (turns == 1)
      printf("You have 1 turn left\n");

    else
      printf("You have %d turns left\n", turns);

    // Roll the dice 5 times and print the result to the user
    for (i = 0; i < NUM_DIE; i++)
      rolls[i] = DICE_ROLL;

    printf("You rolled:\n");
    for (i = 0; i < NUM_DIE; i++)
      printf("%d ", rolls[i]);
    printf("\n");

    // Ask the user if they want to re-roll the dice
    reroll(rolls);

    // Ask again according to game requirements
    reroll(rolls);

    assign_categories(rolls, upper, lower);
  }

  return 0;
}
