// ver 1.4 beta  ( string calc with sin/cos/exp/pow)
//TO DO:
// Not ended version on commit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"
// #include "equeue.h"
#include "list.h"
#include "Lexeme.h"

#define BUFFER 200


//int main()
//{
//	char buffer[BUFFER] = { '/0' };
//
//	printf("Enter the mathematical expression:\n");
//
//	gets(buffer);
//
//	static int i = 0;
//
//	char symbol = 0;
//	double result = 0;
//	char expression[BUFFER] = { '/0' };
//	char math_operation[BUFFER] = { '/0' };
//	while (buffer[i] != '\0') {		// cycle if symbol != EOF
//
//		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {
//			symbol = buffer[i];
//			i++;
//		}
//		else if (buffer[i] == "-") {		// search negative numbers
//			if (isdigit(buffer[i++]) == 0) {	// if op[i] is not digit then nothing happens ( 0 == false )
//				symbol = "-";
//				i++;
//			}
//			else {	// if elem is digit
//				int j = 1;
//				expression[0] = '-';
//				for (; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
//					expression[j] = buffer[i];
//				}
//				expression[j] = 0;
//				enqueue(string_to_double(expression));
//			}
//		}
//		else if (isalpha((int)buffer[i])) {  // search math operations
//			int j;
//			for (j = 0; isalpha((int)buffer[i]); j++, i++) {
//				math_operation[j] = buffer[i];
//			}
//			if (is_math_operation(math_operation) == 1) {
//				if (isdigit(buffer[i])) {
//					int j;
//					for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
//						expression[j] = buffer[i];
//					}
//					expression[j] = 0;
//					enqueue(do_math_operation(math_operation, expression));
//				}
//			}
//			else
//				printf("Error: there is no such mathematical operation\n");
//		}
//		else if (isdigit(buffer[i])) {
//			int j;
//			for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
//				expression[j] = buffer[i];
//			}
//			expression[j] = 0;
//			enqueue(string_to_double(expression));
//		}
//		else {
//			i++;
//		}
//
//
//		if (symbol != 0 && (getlength() == 2)) {
//			switch (symbol) {
//			case '+':
//				result = dequeue() + dequeue();
//				break;
//			case '-':
//				result = dequeue() - dequeue();
//				break;
//			case '*':
//				result = dequeue() * dequeue();
//				break;
//			case '/':
//				result = dequeue() / dequeue();
//				break;
//			case '%':
//				result = dequeue() % dequeue();
//				break;
//			}
//			if (buffer[i++] != '\0') {
//				enqueue(result);
//				symbol = 0;
//			}
//		}
//		else if (buffer[i++] == '\0' && (getlength() == 1)) {
//			result = dequeue();
//		}
//
//
//	}
//
//
//	printf("Result = %lf", result);
//
//
//	return 0;
//}

int main()
{
	struct DblLinkedList* list = createDblLinkedList();

	char buffer[BUFFER] = { '/0' };

	printf("Enter the mathematical expression:\n");

	gets(buffer);

	static int i = 0;

	char symbol = 0;
	double result = 0;
	char expression[BUFFER] = { '/0' };
	char math_operation[BUFFER] = { '/0' };
	while (buffer[i] != '\0') {		// cycle if symbol != EOF
		if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {

			struct Lexeme* operation = malloc(sizeof(struct Lexeme));
			operation->type = TYPE_OPERATOR;
			operation->d.valueChar = buffer[i];
			pushBack(list, operation);
			i++;
		}
		else if (buffer[i] == '-') {

			// is negative numbers?

			if (isdigit(buffer[i++]) == 0) {

				// No. if op[i] is not digit then nothing happens ( 0 == false )

				struct Lexeme* operation = malloc(sizeof(struct Lexeme));
				operation->type = TYPE_OPERATOR;
				operation->d.valueChar = buffer[i];
				pushBack(list, operation);
				i++;
			}
			else {
				// Yes.
				// if next elements is digit?
				expression[0] = '-';
				convertNumber(buffer, i, expression, 1, list);
				// 				int j = 1;
				// 				for (; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
				// 					expression[j] = buffer[i];
				// 				}
				// 				expression[j] = 0;
				// 				// push negative numbers to list
				// 				struct Lexeme *operation = malloc(sizeof(struct Lexeme));
				// 				operation->type = TYPE_NUMBER;
				// 				operation->d.valueDouble = string_to_double(expression);
				// 				pushBack(list, operation);
			}
		}
		else if (isalpha((int)buffer[i])) {  // search math operations
			int j;
			for (j = 0; isalpha((int)buffer[i]); j++, i++) {
				math_operation[j] = buffer[i];
			}
			if (is_math_operation(math_operation) == 1) {
				if (isdigit(buffer[i])) {
					int j;
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
			// 			int j;
			// 			for (j = 0; isdigit(buffer[i]) || buffer[i] == '.'; j++, i++) {
			// 				expression[j] = buffer[i];
			// 			}
			// 			expression[j] = 0;
			// 			struct Lexeme *operation = malloc(sizeof(struct Lexeme));
			// 			operation->type = TYPE_NUMBER;
			// 			operation->d.valueDouble = string_to_double(expression);
			// 			pushBack(list, operation);
		}
		else {
			i++;
		}
	}

	int list_length = list->size;
	while( getLength(list) >= 3) {
		struct Lexeme* pLex = getNthq(list, i);
		if (pLex->type == TYPE_OPERATOR) {

			if (pLex->d.valueChar == '*') {

				// TODO: make operation */ (element i-1 */ element i+1), delete (i-1,i,i+1), insert result
				struct Lexeme* plex_before = getNthq(list, (i - 1));
				struct Lexeme* plex_after = getNthq(list, (i + 1));

				result = ((plex_before->d.valueDouble) * (plex_after->d.valueDouble));

				pLex->type = TYPE_NUMBER;
				pLex->d.valueDouble = result;

				deleteNth(list, (i - 1));
				deleteNth(list, (i + 1));
			}

			else if (pLex->d.valueChar == '/') {

				struct Lexeme* plex_before = getNthq(list, (i - 1));
				struct Lexeme* plex_after = getNthq(list, (i + 1));

				result = ((plex_before->d.valueDouble) / (plex_after->d.valueDouble));

				pLex->type = TYPE_NUMBER;
				pLex->d.valueDouble = result;

				deleteNth(list, (i - 1));
				deleteNth(list, (i + 1));
			}

			else if (pLex->d.valueChar == '+') {

				struct Lexeme* plex_before = getNthq(list, (i - 1));
				struct Lexeme* plex_after = getNthq(list, (i + 1));

				result = ((plex_before->d.valueDouble) + (plex_after->d.valueDouble));

				pLex->type = TYPE_NUMBER;
				pLex->d.valueDouble = result;

				deleteNth(list, (i - 1));
				deleteNth(list, (i + 1));
			}

			else if (pLex->d.valueChar == '-') {

				struct Lexeme* plex_before = getNthq(list, (i - 1));
				struct Lexeme* plex_after = getNthq(list, (i + 1));

				result = ((plex_before->d.valueDouble) - (plex_after->d.valueDouble));

				pLex->type = TYPE_NUMBER;
				pLex->d.valueDouble = result;

				deleteNth(list, (i - 1));
				deleteNth(list, (i + 1));
			}
		}
	}

	if (getLength(list) == 1) {
		// TO DO result = data of elem 
	}



	printf("Result = %lf", result);


	return 0;
}

