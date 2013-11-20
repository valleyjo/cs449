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

int rolls[NUM_DIE];
int upper[6];
int lower[7];
int bonus = 0;
int lower_score = 0;
int upper_score = 0;

void display_score(){
  printf("\nYour score so far is: %d\n\n", lower_score + upper_score \
          + bonus);
  printf("%-20s%-5d%-20s%-5d\n", "Ones:", upper[0], "Fours: ", upper[3]);
  printf("%-20s%-5d%-20s%-5d\n", "Twos:", upper[1], "Fives: ", upper[4]);
  printf("%-20s%-5d%-20s%-5d\n\n", "Threes:", upper[2], "Sixes: ", \
          upper[5]);
  printf("Upper Section Bonus: %d\n\n", bonus);

  printf("%-20s%-5d%-20s%-5d\n","Three of a kind:", lower[0] \
                               ,"Four of a kind:", lower[1]);

  printf("%-20s%-5d%-20s%-5d\n","Small Straight:", lower[2] \
                               ,"Large Straight:", lower[3]);

  printf("%-20s%-5d%-20s%-5d\n","Full House:", lower[4] \
                               ,"Yahtzee:",   lower[5]);

  printf("%-20s%-5d\n\n", "Chance", lower[6]);
}

int compare(const void *this, const void *that){
  return (*(int*)this - *(int*)that);
}

void assign_categories(){
  char input[20];
  int category_selection, i, sum = 0;

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

    for (i = 0; i < NUM_DIE; i++)
      if (rolls[i] == category_selection)
        sum += category_selection;

    upper[category_selection - 1] = sum;
    upper_score += sum;

    if(upper_score > 62)
      bonus = 35;
  }

  // Lower categories
  else{
    printf("\nPlace dice into:\n");
    printf("1) Three of a kind\n");
    printf("2) Four of a kind\n");
    printf("3) Small Straight\n");
    printf("4) Large Straight\n");
    printf("5) Full House\n");
    printf("6) Yahtzee\n");
    printf("7) Chance\n\n");

    printf("Selection: ");
    fgets(input, sizeof(input), stdin);
    category_selection = atoi(input);

    if(category_selection == 1){
      int frequency_of[7];  // Holds the frequency of occurance of each 
                            // possible die value

      int sum = 0;          // sum of the currently rolled hand

      for(i = 0; i < 7; i++)
        frequency_of[i] = 0;

      for(i = 0; i < NUM_DIE; i++){
        // Add 1 to the frequency count of of each possible roll
        int rolled_value = rolls[i];
        frequency_of[rolled_value] += 1;
        sum += rolled_value;
      }

      for(i = 0; i < 7; i++)
        if(frequency_of[i] > 2){
          lower[0] = sum;
          lower_score += sum;
          break;
        }
    }

    if(category_selection == 2){
      int frequency_of[7];  // Holds the frequency of occurance of each 
                            // possible die value

      int sum = 0;          // sum of the currently rolled hand

      for(i = 0; i < 7; i++)
        frequency_of[i] = 0;

      for(i = 0; i < NUM_DIE; i++){
        // Add 1 to the frequency count of of each possible roll
        int rolled_value = rolls[i];
        frequency_of[rolled_value] += 1;
        sum += rolled_value;
      }

      for(i = 0; i < 7; i++)
        if(frequency_of[i] > 3){
          lower[1] = sum;
          lower_score += sum;
          break;
        }
    }
  } // end lower selection areaa
} // end assign_categories90

void reroll(){
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
  int turns, i, dice_to_reroll;
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
    reroll();

    // Ask again according to game requirements
    reroll();

    assign_categories();

    display_score();
  }

  return 0;
}
