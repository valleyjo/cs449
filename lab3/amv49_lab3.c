#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
  int grade;
  struct Node_s *next;
} Node;

int main(){
  Node *root, *cur;
  int input, sum = 0, num_nodes = 0;

  root = malloc(sizeof(Node));
  cur = root;

  printf("Enter -1 to stop.\n");

  while(1) {
    printf("\nEnter a grade: ");
    scanf("%d", &input);

    if (input == -1)
      break;

    cur->grade = input;
    cur->next = malloc(sizeof(Node));
    cur = cur->next;

    num_nodes++;
  }

  cur = root;

  while (cur != NULL){
    sum += cur->grade;
    cur = cur->next;
  }

  while (root != NULL){
    cur = root;
    root = cur->next;
    free(cur);
  }

  printf("\nnum_nodes => %d", num_nodes);
  printf("\nsum => %d", sum);
  printf("\nAverage: %2f\n\n", (double)sum/num_nodes);
}
