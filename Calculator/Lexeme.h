#pragma once

#include <stdio.h>

#define TYPE_OPERATOR 'O'
#define TYPE_NUMBER 'N'
// #define TYPE_FUNCTION 'F'


union data {
	double valueDouble;
	char valueChar;
	// char *valueString;
};

struct Lexeme {
	// 'N' - number
	// 'O' - operator(+,-,...)
	// 'F' - function(cos,sin,...)
	char type;
	union data d;
};
