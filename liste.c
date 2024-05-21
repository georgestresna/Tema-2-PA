#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

void addAtBeginning(Node **head, Team v){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->echipa = v;
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node** head, Team v){
	Node *aux = *head;
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	newNode->echipa = v; 
	if (*head == NULL) addAtBeginning(head, v);
	else{ 
		while (aux->next!=NULL) 
			aux = aux->next;
		aux->next = newNode;
		newNode->next = NULL; 
	}
}