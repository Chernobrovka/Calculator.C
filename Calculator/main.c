#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	static int i = 0;
	int result;
	char expression[BUFFER] = { '/0' };
	char expression_second[BUFFER] = { '/0' };
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
				for (; isdigit(oper[i]) == 1; i++) {						// 36 & 45 string have same testExpression
					/*expression[j] = oper[i] + '0';*/
					strcpy(expression[i], oper[i]);
				}
				enqueue(string_to_int(expression));	// TO DO
				i++;
			}
		}
		else if (isdigit(oper[i]) == 1) {
			for (; oper[i] != " " && oper[i] != "\t" && oper[i] != '\0' && oper[i] != "\n"; i++) {
				/*expression_second[j] = oper[i] + '0';*/
				strcpy(expression_second[i], oper[i]);	
			}
			enqueue(string_to_int(expression_second)); //TO DO
			i++;
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
