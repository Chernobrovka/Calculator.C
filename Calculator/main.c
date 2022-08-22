// ver 1
//TO DO:
//1) Enable opetions on multiple >2 numbers
//2) add sin/cos/abs/pow on math.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "equeue.h"

#define BUFFER 200

int main()
{
	char buffer[BUFFER];

	printf("Enter the mathematical expression:\n");

	gets(buffer);

	static int i = 0;

	char symbol=0;
	int result=0;
	char expression[BUFFER] = { '/0' };
	while (buffer[i] != '\0') {		// cycle if symbol != EOF

		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {
			symbol = buffer[i];
			i++;
		}
		else if (buffer[i] == "-") {		// search negative numbers
			if (isdigit(buffer[++i]) == 0) {	// if op[i] is not digit then nothing happens ( 0 == false )
				symbol = "-";
				i++;
			}
			else {	// if op[i++] is digit ( 1 == true )
				int j=1;
				expression[0] = '-';
				for (; isdigit(buffer[i]); j++,i++) {						// 36 & 45 string have same testExpression
					expression[j] = buffer[i];
				}
				expression[j] = 0;
				enqueue(string_to_int(expression));	// TO DO
			}
		}
		else if (isdigit(buffer[i])) {
			int j;
			for (j = 0; isdigit(buffer[i]); j++, i++) {						// 36 & 45 string have same testExpression
				expression[j] = buffer[i];
			}
			expression[j] = 0;
			enqueue(string_to_int(expression));	// TO DO
		}
		else {
			i++;
		}

	}

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
	printf("%d", result);


	return 0;
}
