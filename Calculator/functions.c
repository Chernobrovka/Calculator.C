#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1000


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
// for transform string to int using::   atoi( const char *str)
