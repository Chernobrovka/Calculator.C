#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "equeue.h"

#define BUFFER 1024
#define OP_SIZE 200

int main()
{
	char oper[BUFFER];
	/*char op[OP_SIZE];*/

	printf("Enter the mathematical expression:\n");
	scanf_s("%199s", oper);

	char symbol;
	int i = 0;
	int result;
	char expression[BUFFER] = "";
	char expression_second[BUFFER] = "";
	while (oper[i] != '\0') {		// cycle if symbol != EOF
		if (oper[i] == " " || oper[i] == "\t") {
			i++;
		}
		else if (oper[i] == "+" || oper[i] == "*" || oper[i] == "/" || oper[i] == "%") {
			symbol = oper[i];
			i++;
		}
		else if (oper[i] == "-") {		// search negative numbers
			if (isdigit(oper[++i]) == 0) {	// if op[i] is not digit then nothing happens ( 0 == false )
				symbol = "-";
				i++;
			}
			else if (isdigit(oper[++i]) == 1) {	// if op[i++] is digit ( 1 == true )
				for (int j = i; isdigit(oper[j]) == 0; j++) {
					expression[j] = oper[i] + '0';
				}
				enqueue(string_to_int(expression));	// TO DO
				i++;
			}
		}
		else if (isdigit(oper[i]) == 1) {
			for (int j = i; oper[j] != " " && oper[j] != "\t" && oper[j] != '\0' && oper[j] != "\n"; j++) {
				expression_second[j] = oper[i] + '0';
			}
			enqueue(string_to_int(expression_second));	// TO DO
		}

	}

	switch (symbol) {
	case '+':
		result = peek() + peek();
		dequeue();
		dequeue();
		printf(result);
		break;
	case '-':
		result = peek() - peek();
		dequeue();
		dequeue();
		printf(result);
		break;
	case '*':
		result = peek() * peek();
		dequeue();
		dequeue();
		printf(result);
		break;
	case '/':
		result = peek() / peek();
		dequeue();
		dequeue();
		printf(result);
		break;
	case '%':
		result = peek() % peek();
		dequeue();
		dequeue();
		printf(result);
		break;
	}


	return 0;
}
