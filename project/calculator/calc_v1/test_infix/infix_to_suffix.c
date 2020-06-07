#include <stdio.h>
#include "calc.h"
#include <ctype.h>

void sym_push(int c);
int sym_pop(void);
void suffix_push(int c);

int get_pri(int c)
{
	switch (c) {
		case '+': return 1; break;
		case '-': return 1; break;
		case '*': return 2; break;
		case '/': return 2; break;
		default : return 0; break;
	}
}

// copy digit from input[] to suffix[]
void copy_digit(void)
{
	while(isdigit(input[ip]) || input[ip] == '.') {
		suffix_push(input[ip++]);
	}
	suffix_push(' ');
}

// convert infix expression to suffix expression
void infix_to_suffix(void)
{
	int c, d;
	ip = 0;
	syp = 0;
	sufp = 0;

	printf("infix: line36\n");
	while ((c = input[ip]) != '\n')
		if (isdigit(c)){
			copy_digit();
			printf("infix: line40\n");
				
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (c == '-' && isdigit(input[ip + 1])){
				suffix_push('-');
				ip++;
				copy_digit();
				continue;
			}
			if (syp > 0 && (get_pri(symbol[syp - 1]) > get_pri(c))){
				printf("infix: line45\n");
				suffix_push(sym_pop())	;
				suffix_push(' ');
			}
			printf("infix: line48\n");
			sym_push(c);
			printf("infix: line49\n");
			ip++;
		}
		else if (c == '(')
			sym_push(c), ip++;
		else if (c == ')'){
			while ((d = sym_pop()) != '('){
				suffix_push(d);
				suffix_push(' ');
			}
			ip++;
		}
		else
			ip++;
	printf("infix: line57\n");
	while (syp > 0) {
		suffix_push(sym_pop());
		suffix_push(' ');
	}
	suffix_push('\n');
}
