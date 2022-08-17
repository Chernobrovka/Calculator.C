#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Queue

struct Node {
	int data;
	struct Node* next;	 // pointer to next node
}*rear = NULL, *front = NULL;

// allocation a new node
struct Node* newNode(int item) {
	// allocation node in heap
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	if (node != NULL) {

		node->data == item;
		node->next = NULL;
		return node;
	}
	else {
		printf("Error: Heap is overflow\n");
		exit(EXIT_FAILURE);
	}
}

// delete first elem of queue
int dequeue() {
	if (front == NULL) {
		printf("Error: Queue is empty\n");
		exit(EXIT_FAILURE);
	}

	struct Node* temp = front;
	printf("Removing %d\n", temp->data);

	//go to next node
	front = front->next;

	// if list becomes empty
	if (front == NULL) {
		rear = NULL;
	}

	// free the memory of node && return the delete elem if necessary
	int item = temp->data;
	free(temp);
	return item;
}

// function for add the elem to queue
void enqueue(int item) {
	//single out new node at heap
	struct Node* node = newNode(item);
	printf("Inserting %d\n", item);

	//if queue is empty
	if (front == NULL) {
		// init the front and back 
		front = node;
		rear = node;
	}
	else {
		// init the back
		rear->next = node;
		rear = node;
	}
}

// return highiest elem of queue
int peek() {
	if (front != NULL) {
		return front->data;
	}
	else {
		exit(EXIT_FAILURE);
	}
}

int isEmpty() {
	return rear == NULL && front == NULL;
}