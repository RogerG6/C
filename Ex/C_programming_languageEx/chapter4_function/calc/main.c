#include "calc.h"

char s[100];
int err = 0;	/* 检测除法错误 */ 

void main(void)
{
	char c;
	double op2;
	
	int j;
	while ((c = getop(s)) != EOF)
	{
		switch(c)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+'   :
				push(pop() + pop());
				break;
			case '*'   :
				push(pop() * pop());
				break;
			case '-'   :
				op2 = pop();
				push(pop() - op2);
				break;
			case '/'   :
				op2 = pop();
				if (op2 != 0) 
					push(pop() / op2);
				else
				{
					err = 1; 
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0) 
					push((int)pop() % (int)op2);
				else
				{
					err = 1; 
					printf("error: zero divisor\n");
				}
				break;				
			case '\n'   :
				if (!err)
				{
					printf("result = %.8g\n", pop());
					err = 0;
				}
				break;
			default	   :
				err = 1;
				printf("error: unknown command %s\n", s);
				break;
		}
#if 0
		printf("s = %s, c = %c, sp = %d, val[]= ", s, c, sp);
		for (j = 0; j < 5; j++)
			printf("%g ", val[j]);
		putchar('\n');
#endif
	}
	
	return;
}

