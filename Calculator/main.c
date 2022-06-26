#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

#define SIZE 100

#define NUMBER 1000

int main(){
    char oper[SIZE];
    int op;
    while((op = get_op(oper)) != 'e'){
        switch (op){
            case NUMBER:
                put(atoi(oper));
                break;
            case '+':
                put(get() + get_op(oper));
                break;
            case '-':
                put(get() - get_op(oper));
                break;
            case '*':
                put(get() * get_op(oper));
                break;
            case '/':
                put(get() / get_op(oper));
                break;    
            default:
                printf("[-]Unknown operator / operand\n");
                break;
        }
    }



    return 0;
}
