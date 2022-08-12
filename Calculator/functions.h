#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STEK_SIZE 100

int doLastOp(char* oper, char lastOp);
int string_to_int(char str[]);
char get_op(char op[]);
void put(int n);
int get(void);
