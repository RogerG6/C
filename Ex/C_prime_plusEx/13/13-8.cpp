# include <stdio.h> 
# include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * fp;
	int ct = 0;
	int ch;
	
	if (argc == 1)
	{
		printf("Error! Usage: %s [character][file1]...", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		printf("Enter a string in stdin:\n");
		while ((ch = getchar()) != '\n')
			if (ch == argv[1][0])
				ct++;
		printf("%c appears %d times in stdin\n", argv[1][0], ct);
	}
	if (argc > 2)
	{
		for (int i = 2; i < argc; i++)
		{
			ct = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				printf("Cant open %s\n", argv[i]);
				continue;
			}
			while ((ch = getc(fp)) != EOF)
				if (ch == argv[1][0])
					ct++;
			printf("%c appears %d times in %s\n", argv[1][0], ct, argv[i]);
			fclose(fp);
		}
	}
	
	return 0;
}
