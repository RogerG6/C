#include <stdio.h>
#include "calc.h"

void infix_to_suffix(void);

int main(void)
{
	int c, i;
	
	// put stdin in input
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		input[i] = c;
	input[i++] = '\n';
	input[i] = '\0';

	infix_to_suffix();

	printf("suffix: %s\n", suffix);
	
	return 0;
}
	
