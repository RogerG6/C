# include <stdio.h> 
# include <stdlib.h>

int main(void)
{
	char name[81];
	FILE * fp;
	long n;
	int ch;
	
	printf("Enter a file's name:");
	scanf("%s", name);
	
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Cant open %s\n", name);
		exit(EXIT_FAILURE);
	}
	printf("Enter a integar:");
	while (scanf("%ld", &n) == 1 && n >= 0)
	{
		fseek(fp, n, SEEK_SET);   //”√fseek∂®Œª 
		while ((ch = getc(fp)) != '\n')
			putchar(ch);
		putchar('\n');
	}
	fclose(fp);
	
	return 0;
}
