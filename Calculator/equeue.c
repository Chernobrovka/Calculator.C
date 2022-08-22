#include "equeue.h"

//Queue

struct Node* front = NULL; // first element (head)
struct Node* rear = NULL; // last element

// allocation a new node
struct Node* newNode(int item) {
	// allocation node in heap
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));

	if (node != NULL) {
		node->data == item;
		node->next = NULL;
		return node;
	}
	printf("Error: Heap is overflow\n");
	exit(EXIT_FAILURE);
}

// delete first elem of queue
int dequeue() {
	if (front == NULL) {
		printf("Error: Queue is empty\n");
		exit(EXIT_FAILURE);
	}

	struct Node* temp = front;
	/*printf("Removing %d\n", temp->data);*/ // for debug

	//go to next node
	front = front->next;

	// if list becomes empty
	if (front == NULL) {
		rear = NULL;
	}

	// return the delete elem if necessary
	int item = temp->data;

	// free the memory of node 
	free(temp);

	return item;
}

// function for add the elem to queue
void enqueue(int item) {
	//single out new node at heap
	struct Node* node = newNode(item);
	node->data = item;

	/*printf("Inserting %d\n", item);*/ // for debug

	//if queue is empty
	if (front == NULL) {
		// init the front and back 
		front = node;
		rear = node;
	} else {
		// init the back
		rear->next = node;
		rear = node;
	}
}

int isEmpty() {
	return front == NULL;
}

int getlength() {
	int len = 0;
	struct Node* el = front;
	if (el == NULL) {
		return len; // 0
	}
	do {
		el = el->next;
		len++;
	} while (el);
	return len;
}

