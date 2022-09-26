// ver 2.0  ( string calc with sin/cos/exp/pow and priority of operations)
//TO DO:
// Abilty to solve equations in brackets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "functions.h"
#include "list.h"
#include "Lexeme.h"

#define BUFFER 600
#define BUFFER_EXPRESSION 256
#define BUFFER_MATH_OP 256


int main()
{
	char symbol = 0;
	double result = 0;
	char expression[BUFFER_EXPRESSION];
	char math_operation[BUFFER_MATH_OP];
	char buffer[BUFFER];

	struct DblLinkedList* list = createDblLinkedList();

	printf("Enter the mathematical expression:\n");

	buffer[0] = 0;
	gets(buffer);

	int i = 0;

	while (buffer[i] != '\0') {		// cycle if symbol != EOF

		if (buffer[i] == ' ') {
			i++;
			continue;
		}

		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {

#ifdef _DEBUG_MAIN
			printf("### operator :%c\n", buffer[i]);
#endif

			struct Lexeme* operation = malloc(sizeof(struct Lexeme));
			operation->type = TYPE_OPERATOR;
			operation->d.valueChar = buffer[i];
			pushBack(list, operation);
			i++;
		}
		else if (buffer[i] == '-') {
			// is negative numbers?
		/*	#ifdef _DEBUG_MAIN
			printf("### Found minus:\n");
			#endif*/

			i++;

			int lenList = getLength(list);
			if (lenList > 0) {
				struct Lexeme* lastop = getNth(list, (lenList - 1))->value;

				if (lastop->type == TYPE_NUMBER) {
					struct Lexeme* operation = malloc(sizeof(struct Lexeme));
					operation->type = TYPE_OPERATOR;
					operation->d.valueChar = '-';
					pushBack(list, operation);
					continue;
				}
			}

			if (isdigit(buffer[i]) == 0) {

				// No. if op[i] is not digit then nothing happens ( 0 == false )

#ifdef _DEBUG_MAIN
				printf("### Minus is operation!\n");
#endif

				struct Lexeme* operation = malloc(sizeof(struct Lexeme));
				operation->type = TYPE_OPERATOR;
				operation->d.valueChar = '-';
				pushBack(list, operation);

			}
			else {
				// Yes.
				// if next elements is digit?

#ifdef _DEBUG_MAIN
				printf("### Minus is start of number\n");
#endif

				expression[0] = '-';
				convertNumber(buffer, &i, expression, 1, list);
			}
		}
		else if (isalpha((int)buffer[i])) {  // search math operations
			int j = 0;
			for (; isalpha((int)buffer[i]); j++, i++) {
				math_operation[j] = buffer[i];
			}
			math_operation[j] = 0;

			if (is_math_operation(math_operation) == 1) {
				while ((buffer[i]) && (isdigit(buffer[i]) == 0)) i++;
				if (isdigit(buffer[i])) {
					int j;
					for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
						expression[j] = buffer[i];
					}
					expression[j] = 0;

					struct Lexeme* operation = malloc(sizeof(struct Lexeme));
					operation->type = TYPE_NUMBER;
					operation->d.valueDouble = do_math_operation(math_operation, expression);
					pushBack(list, operation);
				}
			}
			else
				printf("Error: there is no such mathematical operation\n");
		}
		else if (isdigit(buffer[i])) {

			convertNumber(buffer, &i, expression, 0, list);

		}
		else {
			i++;
		}
	}

	// Create operations in list
	result = createListOperations(list);


	printf("Result = %lf", result);


	return 0;
}

