#include <stdio.h>
#include "calc.h"

int getop(void);
void push(double x);
double pop(void);
void show_stack(void);
void clr_stack(void);
void infix_to_suffix(void);

void calc(void)
{
	int c, i;
	double op1, op2;
//	int op1, op2;
	
	// put stdin in input
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		input[i] = c;
	input[i++] = '\n';
	input[i] = '\0';

	infix_to_suffix(); 
	printf("suffix: %s", suffix);
	
	//printf("calc:  line24\n");
	
	sufp = 0;
	clr_stack();
	while ((c = getop()) != '\0'){ 
		switch (c) {
			case NUMBER:
				push(num);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op1 = pop();
				push(pop() - op1);
				break;
			case '/':
				op1 = pop();
				if (op1 == 0) {
					printf("error: zero division\n");
					return ;
				}
				push(pop() /  op1);
				break;
			case '\n':
				printf("Calculator result = %lf\n",pop());
				break;
			default :
				printf("error: unvalid operator %c\n", c);
				return;
				break;
		}
#if 0
		printf("c = %c ",c);
		show_stack();
		putchar('\n');
#endif
  }
}
