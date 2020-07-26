# include <stdio.h> 
# include <stdlib.h>

int main(void)
{
	FILE * fp;
	int ct = 0;
	int ch;
	char filename[81];
	
	printf("Please enter the filename!\n");
	fscanf(stdin, "%s", filename);
	
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Cant open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		ct++;
	}
	fclose(fp);
	printf("\nFile %s has %d characters\n", filename, ct);
	
	return 0;
}
