#ifndef DLLIST_H_
#define DLLIST_H_

typedef struct node Node;

struct node {
	Node *previous;
    Node *next;
    char *value;

};

Node* createNode(char *value, int size);
void insertAtEnd(Node **head, char *value, int size);
void insertAtBeginning(Node **head, char *value, int size);
void traverseForward(Node *head);
void traverseBackward(Node *head);

#endif