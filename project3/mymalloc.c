/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>

typedef struct node_element *Node;

struct node_element{
  int size;
  char free;
  struct node_element *next;
  struct node_element *prev;
};

Node first;
Node next;
Node last;
void* base;

Node extend_heap(int size){
  Node n;

  n = sbrk(0);
  if (sbrk(sizeof(struct node_element) + size) == (void*)-1)
    return NULL;
  n->size = size;
  n->free = 0;
  n->next = NULL;
  n->prev = last;

  if (last)
    last->next = n;

  return n;
}

/* Run once when the list is first defined
Node init_list(){

  if (sbrk(sizeof(struct Node_s) == (void*)-1))
      return NULL;
  first->size = 0;
  first->free = 1;
  first->next = NULL;
  first->prev = NULL;
}*/

void *my_next_fit_malloc(int size){

  if (base){
    last = base;
    b = find_block(&last, size);
  }

  else (

  if (first == 0){
    last = NULL;
    sbrk(sizeof(struct node_element) + size);
  }
  if (!n)
    return(NULL);
  void *ptr;
  ptr = sbrk(0);

  if (sbrk(size)== (void*)-1)
    return NULL;
  else
    return ptr;
}

void my_free(int *ptr){

}

