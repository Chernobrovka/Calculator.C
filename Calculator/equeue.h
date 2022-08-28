#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Queue 

struct Node {
	int data;
	struct Node* next;	 // pointer to next node
};

// extern struct Node* front;

struct Node* newNode(int item);
int dequeue();
void enqueue(double item);
int isEmpty();
int getlength();