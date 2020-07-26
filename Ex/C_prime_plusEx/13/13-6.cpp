# include <stdio.h> 
# include <stdlib.h>
# include <string.h>
# define LEN 40
int main(void)
{
	FILE * in, * out;
	int ch;
	char ifile[LEN];   //源文件 
	char ofile[LEN];   //目标文件 
	int count = 0;
	
	printf("Enter the input file name:") ;
	scanf("%s", ifile);
	printf("Enter the output file name:");
	scanf("%s", ofile);
	
	if ((in = fopen(ifile, "r")) == 0)
	{
		printf("Cant open %s\n", ifile);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(ofile, "w")) == 0 )
	{
		printf("Cant open %s\n", ofile);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	if (fclose(in) != 0 || fclose(out) != 0)
		printf("Error in closing files\n");
	
	return 0;
}
