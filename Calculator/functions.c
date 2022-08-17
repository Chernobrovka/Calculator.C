#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "equeue.h" 


#define NUMBER 1000
//#define STEKSIZE 1024
//#define BUFFER 100

int string_to_int(char str[]) { // analog of atoi with negative numbers
	int num = 0;
	int neg;
	int i = 0;

	neg = (str[i] == "-") ? -1 : 1;
	if (str[i] == "-")
		i++;
	for (; str[i] != "\0"; i++)
		num = num * 10 + (str[i] - '0');
	return num * neg;
}
