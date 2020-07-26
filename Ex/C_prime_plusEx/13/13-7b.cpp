# include <stdio.h>
# include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * f1, * f2;
	int c1, c2;
//	char * ra, *rb;
//	char tmp1[100];
//	char tmp2[100];

	
	if ((f1 = fopen(argv[1], "r")) == NULL || (f2 = fopen(argv[2], "r")) == NULL)
	{
		printf("Cant open files\n");
		exit(EXIT_FAILURE);
	}
	c1 = getc(f1);
	c2 = getc(f2);
	while (c1 != EOF || c2 != EOF)
	{
		while(c1 != EOF && c1 != '\n')
		{
			putchar(c1);
			c1 = getc(f1);
		
		}
		if (c1 != EOF)
		{
			if (c2 == EOF)   //Èç¹ûc2µ½Ä©Î² 
				putchar('\n');
			else 
				putchar(' ');
			c1 = getc(f1);
		}
		
		while(c2 != EOF && c2 != '\n')
		{
			putchar(c2);
			c2 = getc(f2);
		}
		if(c2 != EOF)
		{
			putchar('\n');
			c2 = getc(f2);
		}
		
	}
	
/*	ra = fgets(tmp1, 100, f1);
	rb = fgets(tmp2, 100, f2);
	
	while (ra != NULL || rb != NULL)
	{
		if (ra != NULL)	
		{
			fputs(tmp1,stdout);
			ra = fgets(tmp1, 100, f1);
			if (ra == NULL)
				putchar('\n');
		}
		
		if ( rb != NULL)
			fputs(tmp2, stdout);
		rb = fgets(tmp2, 100, f2);
	}*/
	fclose(f1);
	fclose(f2);
	
	return 0;
}


