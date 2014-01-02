/*
 * Name: Alex Vallejo 
 * Username: amv49
 * Peoplesoft: 357-8411
 * Date: 12/8/13
 * CS 449 Project 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* 
 * ----------------------------------------------------------------------------
 * Globals
 * ----------------------------------------------------------------------------
 */
char *DELIMS = " ()<>|&;\n\t"; // legal delimiters

/* 
 * ----------------------------------------------------------------------------
 * Return the number of arguments that the user entered
 * ----------------------------------------------------------------------------
 */
int get_num_args(char* input){
  char *curr;
  int count = 0;
  char args[512];

  // copy the argument because this is operation is distructive
  strcpy(args, input);

  curr = strtok(args, DELIMS);
  
  // while the token is not null keep counting
  while(curr != NULL){
    count++;
    curr = strtok(NULL, DELIMS);
  }
  
  return count;
}

int main(){
  char **args, *arg, *path, *cd_path, input[512], token[512];
  int pid = 0, num_args = 0, status, count = 0;

  printf("Welcome to ash, \"Alex's Shell\n\n");

  while(1){
    printf("ash >> ");
    fgets(input, 512, stdin);

    num_args = get_num_args(input);
    args = malloc(sizeof(char*) * (num_args + 1));

    strcpy(token, input);
    arg = strtok(token, DELIMS);
    count = 0;

    while(arg != NULL){
      args[count] = (char*) malloc(sizeof(char) * strlen(arg));
      strcpy(args[count], arg);

      arg = strtok(NULL, DELIMS);
      count++;
    }

    args[num_args] = NULL;

    if(args[0] == NULL)
      continue;

    // check for exit first
    if(strcmp(args[0], "exit") == 0)
      exit(0);

    // change directory
    else if(strcmp(args[0], "cd") == 0)
      if(chdir(args[1]) == -1){
        if(args[1] == NULL)
          printf("cd: : Please specifiy a directory\n");

        else
          printf("cd: %s: No such file or director\n", args[1]);
      }

    // all other commands need to be executed
    else{

      // fork the process so we can destroy it
      pid = fork();

      // if the process is the parent, wait
      if(pid != 0)
        wait(&status);

      else{

        if(strstr(input, ">>") != NULL){
          freopen(args[num_args-1], "a", stdout);

          free(args[num_args-1]);
          args[num_args-1] = NULL;
        }

        else if(strstr(input, ">") != NULL){
          freopen(args[num_args-1], "w", stdout);

          free(args[num_args-1]);
          args[num_args-1] = NULL;
        }

        else if(strstr(input, "<") != NULL){
          freopen(args[num_args-1], "r", stdin);

          free(args[num_args-1]);
          args[num_args-1] = NULL;
        }

        execvp(args[0], args);
        exit(0);
      }// end else
    }// end while
  }// end running of shell
  return 0;
}
