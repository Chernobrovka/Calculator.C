#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1000


int string_to_int( char str[]);
int get_op(char op[]);

int get_op(char op[]){
    static int symbol = 0;
    int i = 0;
    if (symbol == 0) {
        symbol = getchar();
    }
    while (isspace(symbol)){
        symbol = getchar();
    }
    if(!isdigit(symbol)){
        return symbol;
    }
    if (isdigit(symbol)){
        op[i] = symbol;
        while(isdigit(op[++i] = ( c = getchar())));
        op[i] = '\0';

        return NUMBER;
    }
}

// '\0' ---- the null symbol ( end of file)

int str_to_int(char str[]){
    int num = 0;
    int i;
    for(i = 0; str[i] != '\0'; i++ ) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}