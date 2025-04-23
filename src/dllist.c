/*
 * dllist.c
 *
 * Doubly-Linked List
 *
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	Node *previous;
    Node *next;
    char *value;

};

Node* createNode(char *value, int size) {
	char *targetString;

	targetString = malloc(size * sizeof(char));
	if (targetString == NULL) {
		printf("[ERROR] Could not allocate memory for string.\n");
		return NULL;
	}

	strcpy(targetString, value);

	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("[ERROR] Could not allocate memory for Node.\n");
		return NULL;
	}

	newNode->previous = NULL;
	newNode->next = NULL;
	newNode->value = targetString;

	return newNode;
}

void insertAtEnd(Node **head, char *value, int size) {
	Node *newNode = createNode(value, size);

	if (newNode == NULL) {
		printf("[ERROR] Could not create Node.\n");
		return;
	}

	// Check if the head exists yet
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	Node *temp = *head;
	while (temp->next != NULL) {
		temp = temp->next;			// Go to next Node
	}

	temp->next = newNode;			// Point last Node to new Node
	newNode->previous = temp;		// Point new Node to last Node
}

void insertAtBeginning(Node **head, char *value, int size) {
	Node *newNode = createNode(value, size);

	if (newNode == NULL) {
		printf("[ERROR] Could not create Node.\n");
		return;
	}

	// Check if the head exists yet
	if (*head == NULL) {
		*head = newNode;
		return;
	}

	newNode->next = *head;
    (*head)->previous = newNode;
    *head = newNode;

}

// Print list of values of Nodes, starting at head
void traverseForward(Node *head) {
    while (head->next != NULL) {
        printf("%s | ", head->value);
        head = head->next;
    }
    printf("%s\n", head->value);
}