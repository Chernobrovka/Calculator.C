#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define BUFFER_SIZE 200

int main()
{
	char oper[BUFFER_SIZE];
	int r;
	char op;
	char lastOp = 0;
	while ((op = get_op(oper)) != 'e') {
		r = doLastOp(oper, lastOp);
		if (op == '\n') {
			printf("Result = %d\n", get());
		}
		else if (!r) {
			printf("[-]Throw Error:: Unknown operator %c operand\n", op);
		}
		else {
			lastOp = op;
		}
	}

	return 0;
}
