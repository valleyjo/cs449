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
  //TODO implement this function
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
