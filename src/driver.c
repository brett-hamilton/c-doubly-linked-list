/*
 * driver.c
 *
 * Doubly-Linked List
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/dllist.h"

int main(int argc, const char *argv[]) {
	Node *head = NULL;

	char *sourceString = "First string";
	int size = strlen(sourceString) + 1;
	insertAtEnd(&head, sourceString, size);

	sourceString = "Second string";
	size = strlen(sourceString) + 1;
	insertAtEnd(&head, sourceString, size);

	sourceString = "Third string";
	size = strlen(sourceString) + 1;
	insertAtBeginning(&head, sourceString, size);

	printList(head);

	return 0;
}