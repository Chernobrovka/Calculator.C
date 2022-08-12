#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define SIZE 100

#define NUMBER 1000

int main() {
    char oper[SIZE];
    int op;
    while ((op = get_op(oper)) != 'e') {
        switch (op) {
        case NUMBER:
            put(string_to_int(oper));
            break;
        case '+':
            put(get() + ((get_op(oper) == NUMBER) ? string_to_int(oper) : printf("Throw ERROR:: Calculator don't found a number\n")));
            break;
        case '-':
            put(get() - ((get_op(oper) == NUMBER) ? string_to_int(oper) : printf("Throw ERROR:: Calculator don't found a number\n")));
            break;
        case '*':
            put(get() * ((get_op(oper) == NUMBER) ? string_to_int(oper) : printf("Throw ERROR:: Calculator don't found a number\n")));
            break;
        case '/':
            put(get() / ((get_op(oper) == NUMBER) ? string_to_int(oper) : printf("Throw ERROR:: Calculator don't found a number\n")));
            break;
        case '%':
            put(get() % ((get_op(oper) == NUMBER) ? string_to_int(oper) : printf("Throw ERROR:: Calculator don't found a number\n")));
            break;
        case '\n':
            printf("Result = %d\n", get());
            break;
        default:
            printf("[-]Throw Error:: Unknown operator / operand\n");
            break;
        }
    }



    return 0;
}