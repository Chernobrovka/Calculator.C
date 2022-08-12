#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

#define NUMBER 1000


int doLastOp(char* oper, char lastOp)
{
	int num = string_to_int(oper);
	switch (lastOp) {
	case 0:
		put(num);
		break;
	case '+':
		put(get() + num);
		break;
	case '-':
		put(get() - num);
		break;
	case '*':
		put(get() * num);
		break;
	case '/':
		put(get() / num);
		break;
	case '%':
		put(get() % num);
		break;
	default:
		put(num);
		return 0;
	}
	return 1;
}

int string_to_int(char str[])   // analog of atoi with negative numbers
{
	int num = 0;
	int neg;
	int i = 0;

	neg = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-') {
		i++;
	}
	for (; str[i] != 0; i++) {
		num = num * 10 + (str[i] - '0');
	}
	return num * neg;
}

char get_op(char op[])
{
	/*static*/ int symbol = 0;
	int i = 0;
	while (1) { // MAX 6 digits number
		do {   //skipping spaces at the beginning
			symbol = getchar();
		} while (symbol == ' ' || symbol == '\t');
		if (!isdigit(symbol)) {
			op[i] = 0;
			return symbol;
		}
		else {
			op[i] = symbol;
			i++;
		}
	}
}

int stek[STEK_SIZE];
int free_si = 0;

void put(int n)
{
	if (free_si < STEK_SIZE) {
		stek[free_si++] = n;
	}
	else {
		printf("[-]Throw Error: Stek is overflow!\n");
	}
}

int get(void)
{
	if (free_si > 0) {
		return stek[--free_si];
	}
	else {
		printf("[-]Throw Error: Stek is Empty!\n");
	}
}