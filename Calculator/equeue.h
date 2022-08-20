#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Queue 
struct Node;
struct Node* newNode(int item);
int dequeue();
void enqueue(int item);
int isEmpty();