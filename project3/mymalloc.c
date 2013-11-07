/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void print_list();
void* split(int size);

// Using this statement, we can refer to a Node as simply Node without the need
// to use pointers. It saves some typing.
typedef struct node *Node;

/*
 * ----------------------------------------------------------------------------
 * The node structure used to keep track of memory allocations in the heap.
 *  size => number of bytes this allocation contains
 *  free => 1 means true, 0 means false
 *  next => next node in the list. NULL if this node is the first or last node
 *  prev => previous node in the list. NULL if this node is the first node
 * ----------------------------------------------------------------------------
 */
struct node{
  int size;
  int free;
  struct node *next;
  struct node *prev;
};

// static global variables to keep track node locations pertinant to the linked
// list
static Node first = 0;
static Node cur = 0;
static Node last = 0;

/*
 * ----------------------------------------------------------------------------
 * Extend the heap when there is not enough space in the current heap for the
 * requested memory allocation.
 * ----------------------------------------------------------------------------
 */
Node extend_heap(int size){
  Node n;

  n = sbrk(0);
  if (sbrk(sizeof(struct node) + size) == (void*)-1)
    return NULL;

  n->size = size;
  n->free = 0;
  n->next = NULL;
  n->prev = last;

  last->next = n;
  last = n;

  return n;
}

/* ----------------------------------------------------------------------------
 * Run once when the list is first defined. Initializes the list.
 * --------------------------------------------------------------------------*/
static Node init_list(int size){

  first = sbrk(size + sizeof(struct node));

  first->size = size;
  first->free = 0;
  first->next = NULL;
  first->prev = NULL;

  last = first;
  cur = first;

  return first;
}

/*
 * ----------------------------------------------------------------------------
 * Allocate space for a given dynamic memory request. The spaces are kept track
 * of by a linked list woth nodes that store pertinant data RE: the allocation
 * ----------------------------------------------------------------------------
 */
void *my_next_fit_malloc(int size){

  if (first == 0){
    /*printf("First == 0\n");
    init_list(size);

    //Assigning the first node failed :'(
    if (first == NULL)
      return NULL;*/

    // The allocation succeeded! :D
    return (void*)(init_list(size) + 1);
  }

  return (void*)(extend_heap(size) + 1);
}

/*
 * ----------------------------------------------------------------------------
 * Free space previously allocated by malloc. This memory can now be used again
 * Also, colless any contiguous free nodes into one large free node to make
 * larger spaces available for larger allocation requests
 * ----------------------------------------------------------------------------
 */
void my_free(void *ptr){
  Node n = (Node)ptr - 1;
  n->free = 1;
}

/*
 * ----------------------------------------------------------------------------
 * Returns the next available location in the linked list based on the most
 * recent search position.
 * ----------------------------------------------------------------------------
 */
void next_fit(int size){

  if (cur == NULL)
    printf("\n\nCRITICAL ERROR: cur is not assigned. You dropped your\
            pointer :'(\nwhy don't you go cry about it.\n\n");

  if (cur->free == 1 && cur->size > size){
    cur->free = 0;
    cur->size = size;
    split(size);
  }

  while(cur->next != NULL){
    cur = cur->next;
  }
}


void* split(int size){

  Node n = cur + 1 + (size / sizeof(struct node));

  n->free = 0;
  n->next = cur->next;
  n->prev = cur;
  n->size = size;
  cur->next->prev = n;
  cur->next = n;

  return n;
}

/*
 * ----------------------------------------------------------------------------
 * Iterate through the malloc linked list and print each node and respective
 * values.
 * ----------------------------------------------------------------------------
 */
void print_list(){
  Node n = first;
  int i = 0;
  //char free[10];

  if (first != NULL){
    printf("\n\nBegin memory allocation region dump...");

    /*if (n->free == 0)
      strcpy(free, "false");
    else
      strcpy(free, "true");*/

    while(n != NULL){

      printf("\n");
      printf("\nNode: %d", i);
      printf("\nAddr: %d", n);
      printf("\nSize: %d", n->size);
      printf("\nFree: %d", n->free);
      printf("\nNext: %d", n->next);
      printf("\nPrev: %d", n->prev);

      n = n->next;
      i++;
    }// end while

    printf("\n");

  }// end if
}// end print_list:

