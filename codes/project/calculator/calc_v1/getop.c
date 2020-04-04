#include <stdio.h>
#include <ctype.h>
#include "calc.h"


// get an operator or operand from stdin
int getop(void)
{
	int c;
	
	while (suffix[sufp] == ' ' || suffix[sufp] == '\t')
		sufp++;

	if (!isdigit(c = suffix[sufp++]) && c != '-')
		return c;
	
	if (c == '-') 
		if (!isdigit(suffix[sufp]))
			return c;
		else
			sscanf(&suffix[sufp - 1], "%lf", &num);

	if (isdigit(c))
		sscanf(&suffix[sufp - 1], "%lf", &num);

	sufp--;
	while (isdigit(suffix[sufp])  || suffix[sufp] == '-' || suffix[sufp] == '.')
		sufp++;
	
	return NUMBER;
}
