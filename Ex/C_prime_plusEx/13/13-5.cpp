# include <stdio.h> 
# include <stdlib.h>
# include <string.h>
# define BUF 4096
void append(FILE * source, FILE * dest);
//char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
	FILE * fa, * fs;
	int files = 0;
	int ch;
	
	if (argc < 3)
	{
		printf("Error! Usage: %s [append file][source file]...\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		printf("Cant open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUF) != 0)
	{
		printf("Cant create output buffer\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 2; i < argc; i++)
	{
		if (strcmp(argv[i], argv[1]) == 0)
			printf("Cant append file to itself\n");
		else if ((fs = fopen(argv[i], "r")) == NULL)
		{
			printf("Cant open %s\n", argv[i]);
		}
		else 
		{
			if(setvbuf(fs, NULL, _IOFBF, BUF) != 0)
			{
				printf("Cant create input buffer\n");
				continue;
			}	
			append(fs, fa);
			if (ferror (fs) != 0)
				printf("Error in reading file %s\n", argv[i]);
			if (ferror(fa) != 0)
				printf("Error in writing file %s\n", argv[1]);
			fclose(fs);
			files++;
			printf("File %s is appended\n", argv[i]);
		}
	}
	printf("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while ((ch = getc(fa)) != EOF)   //用EOF会有很多空码 
		putchar(ch);
	puts("\nDone displaying.");
	fclose(fa);
	
	return 0;
}

void append(FILE * source, FILE * dest)
{
	size_t bytes;
	static char tmp[BUF];
	
	while ((bytes = fread(tmp, sizeof(char), BUF, source)) > 0)
		fwrite(tmp, sizeof(char), bytes, dest);
}
