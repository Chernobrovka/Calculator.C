#include "inscope.h"

#define _DEBUG_INSCOPE
#define BUFFER 256


double inscope(string buffer) {

#ifdef _DEBUG_INSCOPE
    printf("###IN START IN SCOPE: %s\n",buffer);
#endif

    char expression[BUFFER];
    char math_operation[BUFFER];
    char in_scope_operation[BUFFER];
    double result;
    struct DblLinkedList* list_inscope = createDblLinkedList();

    int i = 0;

    while (buffer[i] != '\0') {
        if (buffer[i] == ' ') {
            i++;
            continue;
        }

        if (buffer[i] == '(') {
            //TO DO
            unsigned int j = 0;
            unsigned int scopes = 1;
            double scopes_result;

            i++;
            while (buffer[i] != 0) {
                in_scope_operation[j] = buffer[i];
                if (buffer[i] == '(') {
                    scopes++;
                }
                else if (buffer[i] == ')') {
                    scopes--;
                    if (scopes == 0) {
                        in_scope_operation[j] = 0;
                        scopes_result = inscope(in_scope_operation);

                        struct Lexeme* operation_inscope = malloc(sizeof(struct Lexeme));
                        operation_inscope->type = TYPE_NUMBER;
                        operation_inscope->d.valueDouble = scopes_result;
                        pushBack(list_inscope, operation_inscope);
                        i++;
                        break;
                    }
                }
                i++;
                j++;
            }
            if((buffer[i] == 0) && (scopes > 0)) {
                printf("ERROR: SECOND SCOPE NOT FOUND!");
                exit(-1);
            }
        }

        if (buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {

            struct Lexeme* operation_inscope = malloc(sizeof(struct Lexeme));
            operation_inscope->type = TYPE_OPERATOR;
            operation_inscope->d.valueChar = buffer[i];
            pushBack(list_inscope , operation_inscope);
            i++;
        }
        else if (buffer[i] == '-') {
            // is negative numbers?
        /*	#ifdef _DEBUG_MAIN
            printf("### Found minus:\n");
            #endif*/

            i++;

            int lenList = getLength(list_inscope);
            if (lenList > 0) {
                struct Lexeme* lastop = getNth(list_inscope, (lenList - 1))->value;

                if (lastop->type == TYPE_NUMBER) {
                    struct Lexeme* operation_inscope = malloc(sizeof(struct Lexeme));
                    operation_inscope->type = TYPE_OPERATOR;
                    operation_inscope->d.valueChar = '-';
                    pushBack(list_inscope, operation_inscope);
                    continue;
                }
            }

            if (isdigit(buffer[i]) == 0) {

                // No. if op[i] is not digit then nothing happens ( 0 == false )


                struct Lexeme* operation_inscope = malloc(sizeof(struct Lexeme));
                operation_inscope->type = TYPE_OPERATOR;
                operation_inscope->d.valueChar = '-';
                pushBack(list_inscope, operation_inscope);

            }
            else {
                // Yes.
                // if next elements is digit?


                expression[0] = '-';
                convertNumber(buffer, &i, expression, 1, list_inscope);
            }
        }
        else if (isalpha((int)buffer[i])) {  // search math operations
            double math_arg;
            double math_result;

            int j = 0;
            for (; isalpha((int)buffer[i]); j++, i++) {
                math_operation[j] = buffer[i];
            }
            math_operation[j] = 0;

            if (is_math_operation(math_operation) == 1 && buffer[++i] == '(') {
                /*while ((buffer[i]) && (isdigit(buffer[i]) == 0)) i++;
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
                }*/
                i++;
                int g = 0;
                while (buffer[i] != ')') {
                    in_scope_operation[g] = buffer[i];
                    g++;
                    i++;
                }
                in_scope_operation[g] = 0;

                math_arg = inscope(in_scope_operation);
                math_result = do_math_operation(math_operation, math_arg);

                struct Lexeme* operation_inscope = malloc(sizeof(struct Lexeme));
                operation_inscope->type = TYPE_NUMBER;
                operation_inscope->d.valueDouble = math_result;
                pushBack(list_inscope, operation_inscope);
            }
            else
                printf("Error: there is no such mathematical operation\n");
        }
        else if (isdigit(buffer[i])) {

            convertNumber(buffer, &i, expression, 0, list_inscope);

        }
        else {
            i++;
        }

    }

    result = createListOperations(list_inscope);

#ifdef _DEBUG_INSCOPE
    printf("### RESULT IN SCOPE %lf\n",result);
#endif

    return result;
}

int get_level(string buffer) {
    int i = 0;
    int scopes = 0;
    while (buffer[i] != '\0') {
        if (buffer[i] == '(') {
            scopes++;
        }
        i++;
    }
    return scopes;
}
