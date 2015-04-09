#include "list.h"
#include <iostream>
using namespace std;

void reverseList(Node** head){
	Node* current = *head;
	Node* previous = NULL;
	Node* next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}
void delLesserNodes(Node* head){
	Node* current = head;
	Node* maxNode = head;
	Node* temp = NULL;
	while(current != NULL && current->next != NULL){
		if(current->next->data < maxNode->data){
			temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		else{
			maxNode = current->next;
			current = current->next;
		}
	}
}

int delRight(Node** head){
	reverseList(head);
	delLesserNodes(*head);
	reverseList(head);
	return 0;
}

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	push(&head,24);
	push(&head,16);
	push(&head,21);
	push(&head,15);
	push(&head,20);
	push(&head,10);
	printList(head);
	delRight(&head);
	printList(head);
	return 0;
}