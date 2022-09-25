#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char* string;

int string_to_int(char str[]);

int is_math_operation(char str[]);

double do_math_operation(char* math[], char* exp[]);

double string_to_double(char s[]);

void convertNumber(char* buffer, int i, char* expression, int j, struct DblLinkedList* list);

double createListOperations(struct DblLinkedList* list);