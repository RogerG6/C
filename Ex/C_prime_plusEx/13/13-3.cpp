# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void to_up(FILE * fs, FILE * ft);

int main(void)
{
	FILE * fs, * ft;
	char fns[81];
	char fnt[81];
	
	printf("Enter a input filename:");
	fscanf(stdin, "%s", fns);
	printf("Enter a output filename:");
	fscanf(stdin, "%s", fnt);
	
	if ((fs = fopen(fns, "r")) == NULL)
	{
		printf("Cant open %s\n", fns);
		exit(EXIT_FAILURE);
	}
	if ((ft = fopen(fnt, "w")) == NULL)
	{
		printf("Cant open %s\n", fnt);
		exit(EXIT_FAILURE);
	}
	to_up(fs, ft);
	
	fclose(fs);
	fclose(ft);
	
	
	return 0;
}

void to_up(FILE * fs, FILE * ft)
{
	int c;
	while ((c = getc(fs)) != EOF)
	{
		if (isalpha(c))
			putc(toupper(c), ft);
		else
			putc(c, ft);
	}
}
