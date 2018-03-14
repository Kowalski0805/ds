#include <stdlib.h>
#include <stdio.h>

// Singly linked list structure

typedef struct singly_node {
  int data;
  struct singly_node * next;
} singly_node_t;

void unshift_singly_node(singly_node_t ** first, int data) {
  singly_node_t * new_first = NULL;
  new_first = malloc(sizeof(singly_node_t));
  new_first->data = data;
  new_first->next = *first;
  *first = new_first;
}


// Doubly linked list structure

typedef struct doubly_node {
  int data;
  struct doubly_node * next;
  struct doubly_node * prev;
} doubly_node_t;

void unshift_doubly_node(doubly_node_t ** first, int data) {
  doubly_node_t * new_first = NULL;
  new_first = malloc(sizeof(doubly_node_t));
  new_first->data = data;
  new_first->prev = NULL;
  new_first->next = *first;
  new_first->next->prev = new_first;
  *first = new_first;
}

// Usage

int main() {

  // Singly

  singly_node_t * singly_first = NULL;
  singly_first = malloc(sizeof(singly_node_t));

  singly_first->data = 1820;
  singly_first->next = NULL;
  printf("Singly first: %d\n", singly_first->data);

  unshift_singly_node(&singly_first, 20);
  printf("Singly first after unshift: %d\n", singly_first->data);

  free(singly_first->next);
  free(singly_first);

  // Outputs garbage because of free()
  // should be deleted or repointed to new allocated memory for a struct
  printf("Old singly first (garbage): %i\n\n", singly_first->data);


  //Doubly

  doubly_node_t * doubly_first = NULL;
  doubly_first = malloc(sizeof(doubly_node_t));

  doubly_first->data = 2020;
  doubly_first->next = NULL;
  doubly_first->prev = NULL;
  printf("Doubly first: %d\n", doubly_first->data);

  unshift_doubly_node(&doubly_first, 4040);
  printf("Doubly first after unshift: %d\n", doubly_first->next->prev->data);
  printf("Doubly second: %d\n", doubly_first->next->data);

  free(doubly_first->next);
  free(doubly_first);

  return 0;
}
