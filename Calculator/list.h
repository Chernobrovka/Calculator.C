#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
	void* value;
	struct Node* next;
	struct Node* prev;
};

struct DblLinkedList {
	size_t size;
	struct Node* head;
	struct Node* tail;
};


struct DblLinkedList* createDblLinkedList();

void deleteDblLinkedList(struct DblLinkedList** list);

void pushFront(struct DblLinkedList* list, void* data);

void* popFront(struct DblLinkedList* list);

void pushBack(struct DblLinkedList* list, void* value);

void* popBack(struct DblLinkedList* list);

struct Node* getNth(struct DblLinkedList* list, size_t index);

void insert(struct DblLinkedList* list, size_t index, void* value);

void* deleteNth(struct DblLinkedList* list, size_t index);

void printDblLinkedList(struct DblLinkedList* list, void (*fun)(void*));

struct DblLinkedList* fromArray(void* arr, size_t n, size_t size);

int getLength(struct DblLinkedList* list);



