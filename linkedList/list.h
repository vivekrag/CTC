#include <stdio.h>
#include <stdlib.h>
using namespace std;

// A linked list node
struct node
{
  int data;
  struct node *next;
};
typedef struct node Node;
/* Given a reference (pointer to pointer) to the head of a list and an int,
   inserts a new node on the front of the list. */
void push(struct node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 	//Node* new_node = new Node();
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Utility function to print a linked list */
void printList(struct node *head)
{
     while(head!=NULL)
     {
        printf("%d ",head->data);
        head=head->next;
     }
     printf("\n");
}