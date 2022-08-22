// ver 1.2
//TO DO:
//1) add sin/cos/abs/pow on math.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"
#include "equeue.h"

#define BUFFER 200

int main()
{
	char buffer[BUFFER] = { '/0' };

	printf("Enter the mathematical expression:\n");

	gets(buffer);

	static int i = 0;

	char symbol=0;
	double result=0;
	char expression[BUFFER] = { '/0' };
	char math_operation[BUFFER] = { '/0' };
	while (buffer[i] != '\0') {		// cycle if symbol != EOF

		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {
			symbol = buffer[i];
			i++;
		}
		else if (buffer[i] == "-") {		// search negative numbers
			if (isdigit(buffer[i++]) == 0) {	// if op[i] is not digit then nothing happens ( 0 == false )
				symbol = "-";
				i++;
			}
			else {	// if elem is digit
				int j=1;
				expression[0] = '-';
				for (; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
					expression[j] = buffer[i];
				}
				expression[j] = 0;
				enqueue(string_to_double(expression));
			}
		}
		/*else if (isalpha((int)buffer[i])) {
			int j;
			for (j = 0; isalpha((int)buffer[i]); j++, i++) {
				math_operation[j] = buffer[i];
				
			}
		}*/
		else if (isdigit(buffer[i])) {
			int j; 
			for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
				expression[j] = buffer[i];
			}
			expression[j] = 0;
			enqueue(string_to_double(expression));	
		}
		else {
			i++;
		}

		
		if (symbol != 0 && (getlength() == 2)) {
			switch (symbol) {
			case '+':
				result = dequeue() + dequeue();
				break;
			case '-':
				result = dequeue() - dequeue();
				break;
			case '*':
				result = dequeue() * dequeue();
				break;
			case '/':
				result = dequeue() / dequeue();
				break;
			case '%':
				result = dequeue() % dequeue();
				break;
			}
			if (buffer[i++] != '\0') {
				enqueue(result);
				symbol = 0;
			}
		}
			

	}

	
	printf("%lf", result);


	return 0;
}
