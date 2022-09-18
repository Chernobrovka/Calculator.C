#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "equeue.h"
#include "Lexeme.h"
#include "list.h"

#define ACOS "acos"
#define ASIN "asin"
#define ATAN "atan"
#define COS "cos"
#define SIN "sin"
#define EXP "exp"
#define LOG "log"
#define LG "lg" // log10
#define POW "pow"  // only to 2 
#define SQRT "sqrt"



int string_to_int(char str[]) { // analog of atoi with negative numbers

#ifdef _DEBUG_StringToInt
	printf("### String_to_int RUN:");
	printf("String: %50c", str);
#endif

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
	
#ifdef _DEBUG_isMath
	printf("###	is_math_operation RUN:");
	printf("Operation: %5c", str);
#endif
	
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

double do_math_operation(char* math[], char* expr[]) {
	double result;
	if (strcmpi(math, ACOS) == 0) {
		result = acos(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, ASIN) == 0) {
		result = asin(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, ATAN) == 0) {
		result = atan(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, COS) == 0) {
		result = cos(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, SIN) == 0) {
		result = sin(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, EXP) == 0) {
		result = exp(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, LOG) == 0) {
		result = log(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, LG) == 0) {
		result = log10(string_to_double(expr));
		return result;
	}
	else if (strcmpi(math, POW) == 0) {
		result = pow(string_to_double(expr), 2.0);
		return result;
	}
	else if (strcmpi(math, SQRT) == 0) {
		result = sqrt(string_to_double(expr));
		return result;
	}
}

double string_to_double(char s[])
{

#ifdef _DEBUG_StringToDouble
	printf("### String_to_double RUN:");
	printf("String: %50c", str);
#endif

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

void convertNumber(char* buffer, int i, char* expression, int j, struct DblLinkedList* list)
{

#ifdef _DEBUG_ConvertNumber
	printf("### Convert Number RUN:");
	printf("String: %50c", buffer);
	printf("Index: %d", i);
	printf("Expression: %10c", expression);
	printf("Index j: %d", j);
#endif

	for (; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
		expression[j] = buffer[i];
	}
	expression[j] = 0;
	struct Lexeme* operation = malloc(sizeof(struct Lexeme));
	operation->type = TYPE_NUMBER;
	operation->d.valueDouble = string_to_double(expression);
	pushBack(list, operation);
}