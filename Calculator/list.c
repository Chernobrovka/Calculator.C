#include "list.h"

//#define _DEBUG_GETLENGTH

struct DblLinkedList* createDblLinkedList() {
    struct DblLinkedList* tmp = (struct DblLinkedList*)malloc(sizeof(struct DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}


void deleteDblLinkedList(struct DblLinkedList** list) {
    struct Node* tmp = (*list)->head;
    struct Node* next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(struct DblLinkedList* list, void* data) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}


void* popFront(struct DblLinkedList* list) {
    struct Node* prev;
    void* tmp;
    if (list->head == NULL) {
        exit(2);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

void pushBack(struct DblLinkedList* list, void* value) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void* popBack(struct DblLinkedList* list) {
    struct Node* next;
    void* tmp;
    if (list->tail == NULL) {
        exit(4);
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);

    list->size--;
    return tmp;
}

struct Node* getNth(struct DblLinkedList* list, size_t index) {
    struct Node* tmp = NULL;
    size_t i;

    if (index < list->size / 2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    }
    else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }

    return tmp;
}

void insert(struct DblLinkedList* list, size_t index, void* value) {
    struct Node* elm = NULL;
    struct Node* ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (struct Node*)malloc(sizeof(struct Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

void* deleteNth(struct DblLinkedList* list, size_t index) {
    struct Node* elm = NULL;
    void* tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}


void printDblLinkedList(struct DblLinkedList* list, void (*fun)(void*)) {
    struct Node* tmp = list->head;
    while (tmp) {
        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


struct DblLinkedList* fromArray(void* arr, size_t n, size_t size) {        // create list from array
    struct DblLinkedList* tmp = NULL;
    size_t i = 0;
    if (arr == NULL) {
        exit(7);
    }

    tmp = createDblLinkedList();
    while (i < n) {
        pushBack(tmp, ((char*)arr + i * size));
        i++;
    }

    return tmp;
}

int getLength(struct DblLinkedList* list) {
    int result = list->size;

    #ifdef _DEBUG_GETLENGTH
         printf("Elems in list: %d\n\n", result);
    #endif
    return result;
}
