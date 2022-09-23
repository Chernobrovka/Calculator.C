// ver 1.4 beta  ( string calc with sin/cos/exp/pow)
//TO DO:
// Not ended version on commit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "functions.h"
#include "list.h"
#include "Lexeme.h"

#define BUFFER 200
#define BUFFER_EXPRESSION 10
#define BUFFER_MATH_OP 4


int main()
{
	struct DblLinkedList* list = createDblLinkedList();

	char buffer[BUFFER] = { '/0' };

	printf("Enter the mathematical expression:\n");

	gets(buffer);

	static int i = 0;

	char symbol = 0;
	double result = 0;
	char expression[BUFFER_EXPRESSION] = { '/0' };
	char math_operation[BUFFER_MATH_OP] = { '/0' };
	while (buffer[i] != '\0') {		// cycle if symbol != EOF
		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {

			struct Lexeme* operation = malloc(sizeof(struct Lexeme));
			operation->type = TYPE_OPERATOR;
			operation->d.valueChar = buffer[i];
			pushBack(list, operation);
			i++;
		}
		else if (buffer[i] == '-') {
			
			#ifdef _DEBUG_MAIN
			printf("### Found minus:\n");
			#endif

			// is negative numbers?

			if (isdigit(buffer[i++]) == 0 ) {

				// No. if op[i] is not digit then nothing happens ( 0 == false )

				struct Lexeme* operation = malloc(sizeof(struct Lexeme));
				operation->type = TYPE_OPERATOR;
				operation->d.valueChar = buffer[i];
				pushBack(list, operation);
			}
			else {
				// Yes.
				// if next elements is digit?

				/*expression[0] = '-';
				convertNumber(buffer, i, expression, 1, list);*/

				short int j = 1;
				expression[0] = '-';
				for (; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
				 	expression[j] = buffer[i];
				 }
				
				expression[j] = 0;

				#ifdef _DEBUG_MAIN
				printf("### Negative Number: ");
				printf("%s\n", expression);

				#endif

				// push negative numbers to list
				struct Lexeme *operation = malloc(sizeof(struct Lexeme));
				operation->type = TYPE_NUMBER;
				operation->d.valueDouble = string_to_double(expression);
				pushBack(list, operation);
				i++;
			}
		}
		else if (isalpha((int)buffer[i])) {  // search math operations
			short int j;
			for (j = 0; isalpha((int)buffer[i]); j++, i++) {
				math_operation[j] = buffer[i];
			}
			if (is_math_operation(math_operation) == 1) {
				if (isdigit(buffer[i])) {
					short int j;
					for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
						expression[j] = buffer[i];
					}
					expression[j] = 0;
					struct Lexeme* operation = malloc(sizeof(struct Lexeme));
					operation->type = TYPE_OPERATOR;
					operation->d.valueChar = expression;
					pushBack(list, operation);
				}
			}
			else
				printf("Error: there is no such mathematical operation\n");
		}
		else if (isdigit(buffer[i])) {
			convertNumber(buffer, i, expression, 0, list);
			i++;
			
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


