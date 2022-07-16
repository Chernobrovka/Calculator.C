#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1000


int get_op(char op[]);

int get_op(char op[]){
    /*static*/ int symbol = 0;
    static int remember = 0;
    int i = 0;
    if (remember != 0) {
        symbol = remember;
        remember = 0;
    }
    else {
        symbol = getchar();
    }
    while ( symbol == ' ' || symbol == '\t' ){   //skipping spaces at the beginning
        symbol = getchar();
    }
    if(!isdigit(symbol)){
        return symbol;  
    }
    if (isdigit(symbol)){
        op[i] = symbol;
        while(isdigit(op[++i] = ( symbol = getchar())));
        op[i] = '\0';

        return NUMBER;
    }
}

// '\0' ---- the null symbol ( end of file)
// for transform string to int using::   atoi( const char *str)

#define STEKSIZE 100
int stek[STEKSIZE];
int free_si = 0;

void put ( int n ){
    if ( free_si < STEKSIZE ){
        stek[free_si++] = n;
    }
    else{
        printf ("[-]Throw Error: Stek is overflow!");
    }
}

int get(void){
    if ( free_si > 0){
        return stek[--free_si];
    }
    else{
        printf("[-]Throw Error: Stek is Empty!");
    }
}