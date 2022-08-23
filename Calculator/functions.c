#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "equeue.h" 

#define ACOS "acos"
#define ASIN "asin"
#define ATAN "atan"
#define COS "cos"
#define SIN "sin"
#define EXP "exp"
#define LOG "log"
#define LG "lg" // log10
#define POW "pow"
#define SQRT "sqrt"


int string_to_int(char str[]) { // analog of atoi with negative numbers
	int num = 0;
	int neg;
	int i = 0;

	neg = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-')
		i++;
	for (; str[i] != 0; i++)
		num = num * 10 + (str[i] - '0');
	return num * neg;
}

int is_math_operation(char str[]) {	// compares string and math compares
	extern math_operation;
	
	if (strcmpi(str, ACOS) == 0) {
		return 1;
	}
	else if (strcmpi(str, ASIN) == 0) {
		return 1;
	}
	else if (strcmpi(str, ATAN) == 0) {
		return 1;
	}
	else if (strcmpi(str, COS) == 0) {
		return 1;
	}
	else if (strcmpi(str, SIN) == 0) {
		return 1;
	}
	else if (strcmpi(str, EXP) == 0) {
		return 1;
	}
	else if (strcmpi(str, LOG) == 0) {
		return 1;
	}
	else if (strcmpi(str, LG) == 0) {
		return 1;
	}
	else if (strcmpi(str, POW) == 0) {
		return 1;
	}
	else if (strcmpi(str, SQRT) == 0) {
		return 1;
	}
	else {
		return -1;
		printf("Error: there is no such mathematical operation");
	}
}

double string_to_double(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)
		; /* ignore separator characters */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}
