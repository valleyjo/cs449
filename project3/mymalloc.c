/* Name: Alex Vallejo
 * Username: amv49
 * Peoplesoft: 357811
 * Date: 11/5/2013
 * CS 449 Project 3
 */

#include <stdio.h>
#include <unistd.h>

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
  char free;
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
 * resuested memory allocation.
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

  init_list(size);

  if (first == 0){
    printf("First == 0\n");
    //init_list();

    // Assigning the first node failed :'(
    //if (first == NULL)
      //return NULL;
  }

  void *ptr;
  ptr = sbrk(0);

  if (sbrk(size)== (void*)-1)
    return NULL;
  else
    return ptr;
}

/*
 * ----------------------------------------------------------------------------
 * Free space previously allocated by malloc. This memory can now be used again
 * Also, colless any contiguous free nodes into one large free node to make
 * larger spaces availabel for larger allocation requests
 * ----------------------------------------------------------------------------
 */
void my_free(int *ptr){

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

  if (first != NULL){
    printf("\n\nBegin memory allocation region dump...");
    while(n != NULL){
      printf("\n");
      printf("\nNode: %d", i);
      printf("\nAddr: %d", n);
      printf("\nSize: %d", n->size);
      printf("\nFree: %d", n->free);
      printf("\nNext: %d", n->next);
      printf("\nPrev: %d", n->prev);
      printf("\n");

      n = n->next;
      i++;
    }// end while
  }// end if
}// end print_list:

