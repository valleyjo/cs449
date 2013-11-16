/* Username: amv49
 * Peoplesoft: 357811
 * Date: 11/15/2013
 * CS 449 Project 4
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void reroll(int rolls[]){
  char input[10], *token[10];
  int i, reroll[5], num_rerolls = 0;

  for(i = 0; i < 5; i++)
    reroll[i] = 0;

  //TODO implement this function
  // set each value in the reroll array to zero
  printf("\nWhich dice do you want to re-roll: ");
  fgets(input, sizeof(input), stdin);

  i = 0;
  token[0] = strtok(input, " ");
  while(token[i] != NULL){
    reroll[i] = 0;
    //printf("\n%s", token[i]);
    int dice_to_reroll = atoi(token[i]) - 1;
    //printf("dice to reroll => %d", dice_to_reroll);
    reroll[dice_to_reroll] = 1;

    num_rerolls = i;
    i++;
    token[i] = strtok(NULL, " ");
    //reroll[dice_to_reroll] = 1;
    //printf("rerolls[%d] => %d", i, rerolls[i] );
  }

  for(i = 0; i < 5; i++){
    printf("\nreroll[%d] => %d", i, reroll[i]);
  }
  //printf("\n1\n");
  //reroll[0] = 1;
  //reroll[1] = 0;

  for(i = 0; i < 2; i++)
    if(reroll[i] == 1)
      rolls[i] = rand() % 6 + 1;

  printf("\nYour reroll is:\n");
  for(i = 0; i < 5; i++)
    printf("%d ", rolls[i]);
  printf("\n");

}

int main(){

  int turns, i, dice_to_reroll;
  char pluralize_turn[15], input[20];
  int rolls[5];

  srand(time(NULL));

  for (turns = 13; turns > 0; turns--){
    if (turns == 1)
      strcpy(pluralize_turn, "turn");
    else
      strcpy(pluralize_turn, "turns");

    printf("\nYou have %d %s left\n", turns, pluralize_turn);

    // Roll the dice 5 times and print the result to the user
    for (i = 0; i < 5; i++)
      rolls[i] = rand() % 6 + 1;

    printf("You rolled:\n");
    for (i = 0; i < 5; i++)
      printf("%d ", rolls[i]);
    printf("\n");

    // Ask the user if they want to re-roll the dice
    reroll(rolls);

    // Ask again according to game requirements
    reroll(rolls);
  }

  return 0;
}
