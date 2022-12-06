#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"

typedef char* string;

int string_to_int(char str[]);

int is_math_operation(char str[]);

double do_math_operation(char* math, double expr);

double string_to_double(char s[]);

void convertNumber(char* buffer, int* i, char* expression, int j, struct DblLinkedList* list);

double createListOperations(struct DblLinkedList* list);
