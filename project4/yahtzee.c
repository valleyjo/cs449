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
  char score_1[15], score_2[15];
  printf("\nYour score so far is: %d\n\n", lower_score + upper_score + bonus);

  // Print 1's and 4's score
  if(upper[0] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", upper[0]);
  if(upper[3] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", upper[3]);
  printf("%-20s%-5s%-20s%-5s\n", "Ones:", score_1, "Fours: ", score_2);

  // Print 2's and 5's score
  if(upper[1] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", upper[1]);
  if(upper[4] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", upper[4]);
  printf("%-20s%-5s%-20s%-5s\n", "Twos:", score_1, "Fives: ", score_2);

  // Print 3's and 6's score
  if(upper[2] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", upper[2]);
  if(upper[5] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", upper[5]);
  printf("%-20s%-5s%-20s%-5s\n\n", "Threes:", score_1, "Sixes: ", score_2);

  // Print 3's and 6's score
  printf("Upper Section Bonus: %d\n\n", bonus);

  // Print 3 and 4 of a kind
  if(lower[0] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", lower[0]);
  if(lower[1] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", lower[1]);
  printf("%-20s%-5s%-20s%-5s\n","Three of a kind:", score_1, "Four of a kind:", score_2);

  // Print Small straight and large straight
  if(lower[2] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", lower[2]);
  if(lower[3] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", lower[3]);
  printf("%-20s%-5s%-20s%-5s\n","Small Straight:", score_1,"Large Straight:", score_2);

  // Print Small straight and large straight
  if(lower[4] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", lower[4]);
  if(lower[5] == -1)
    strcpy(score_2, "na");
  else
    sprintf(score_2, "%d", lower[5]);
  printf("%-20s%-5s%-20s%-5s\n","Full House:", score_1,"Yahtzee:", score_2);

  // Print chance
  if(lower[6] == -1)
    strcpy(score_1, "na");
  else
    sprintf(score_1, "%d", lower[6]);
  printf("%-20s%-5s\n\n", "Chance:", score_1);
}

int compare(const void *this, const void *that){
  return (*(int*)this - *(int*)that);
}

int valid_selection(char upper_lower){
  char input[20];
  int category_selection;

  while(1){
    printf("\nSelection: ");
    fgets(input, sizeof(input), stdin);
    category_selection = atoi(input);

    if(upper_lower == 'u'){
      if(category_selection < 0 || category_selection > 6)
        printf("Invalid selection. No category #%d in upper categories", category_selection);

      else if(upper[category_selection - 1] == -1)
        return category_selection;

      printf("Invalid selection. Upper category #%d already assigned", category_selection);
    }

    else if(upper_lower == 'l'){
      if(category_selection < 0 || category_selection > 7)
        printf("Invalid selection. No category #%d in upper categories", category_selection);

      else if(lower[category_selection - 1] == -1)
        return category_selection;

      printf("Invalid selection. Lower category #%d already assigned", category_selection);
    }

    else{
      printf("\n\nERROR: invalid parameter in valid_selection(char). Parameter does not equal 'l' or 'u'");
      exit(1);
    }// end else for invalid parameter
  }// end while(1) for repeated inputs
}// end valid_selection()

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

    category_selection = valid_selection('u');

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

    category_selection = valid_selection('l');

    // Three of a kind
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

    // Four of a kind
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

    // Full House
    if(category_selection == 3){
      printf("\n\nFull House");
      if(rolls[0] == rolls[1] && (rolls[2] == rolls[3]) && (rolls[3] == rolls[4])){
        lower_score += 25;
        lower[2] = 25;
      }

      else if((rolls[0] == rolls[1]) && (rolls[1] == rolls[2]) && rolls[3] == rolls[4]);{
        lower_score += 25;
        lower[2] = 25;
      }
    }

    // Small straight
    if(category_selection == 4){
      if(rolls[0] < rolls[1] && rolls[1] < rolls[2] && rolls[2] < rolls[3] && rolls[3] < rolls[4]){
        lower[3] = 30;
        lower_score += 30;
      }
    }

    // Large straight
    if(category_selection == 5){
      if(rolls[1] < rolls[2] && rolls[2] < rolls[3] && rolls[3] < rolls[4] && rolls[4] < rolls[5]){
        lower[4] = 40;
        lower_score += 40;
      }
    }

    // Yahtzee
    if(category_selection == 6){
      if(rolls[0] == rolls[1] && rolls[1] == rolls[2] && rolls[2] == rolls[3] && rolls[3] == rolls[4] && rolls[4] == rolls[5]){
        lower_score += 50;
        lower[5] = 50;
      }
    }

    // Chance
    if(category_selection == 7){
      sum = 0;
      for(i = 0; i < NUM_DIE; i++){
        sum += rolls[i];
      }
      lower[6] = sum;
      lower_score += sum;
    }

  } // end lower selection areaa
} // end assign_categories()

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

  // initialize all categories to -1 to indicate they have not been assigned
  for(i = 0; i < 6; i++)
    upper[i] = -1;
  for(i = 0; i < 7; i++)
    lower[i] = -1;

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

    qsort(rolls, NUM_DIE, sizeof(int), compare);

    assign_categories();

    display_score();
  }

  return 0;
}
