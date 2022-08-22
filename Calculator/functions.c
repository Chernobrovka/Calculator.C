#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "equeue.h" 

#define ACOS "acos"
#define ASIN "asin"
#define ATAN "atan"
#define COS "cos"

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

//void is_math_operation(char str[]) {	// compares string and math compares
//	extern math_operation;
//	/*strcmpi()*/
//}

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

