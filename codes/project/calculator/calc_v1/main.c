#include <stdio.h>
#include "calc.h"

void calc(void);

int main(void)
{
	while (1) {
		printf("*************calculator*****************\n");
		printf("Enter the expression: ");
		calc();
		printf("\nContinue?\n");
		if (getchar() == 'q')
			break;
	}

	return 0;
}
