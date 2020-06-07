#include <stdio.h>
#include "calc.h"
#define MAXNUM 100

double stack[MAXNUM];
//int stack[MAXNUM];
int sp = 0;

void push(double x)
{
	if (sp < MAXNUM)
		stack[sp++] = x;
	else {
		printf("error: stack is full\n");
		return;
	}
//	printf("sp = %d\n", sp);
}

double pop(void)
{
	if (sp > 0)
		return stack[--sp];
	else {
		printf("error: stack is empty\n");
		return -1;
	}
}

void show_stack(void)
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%lf ", stack[i]);
}




void sym_push(int c)
{
	if (syp >= MAXLEN) {
		printf("error: symbol stack is full\n");
		return;
	} else
		symbol[syp++] = c;
}

int sym_pop(void)
{
	if (syp > 0)
		return symbol[--syp];
	else {
		printf("error: symbol stack is empty\n");
		return -1;
	}
}


void suffix_push(int c)
{
	if (sufp >= MAXLEN) {
		printf("error: suffix stack is full\n");
		return;
	} else
		suffix[sufp++] = c;
}
