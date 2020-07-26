# include <stdio.h>
# include <stdlib.h>
# define SIZE 81
int main(int argc, char * argv[])
{
	
	char  tmp[SIZE];
	FILE * fs, * ft;
	int n; 
	
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		printf("Cant open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((ft = fopen(argv[2], "wb")) == NULL)
	{
		printf("Cant open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while ((n = fread(tmp, sizeof(char), 10, fs)) > 0)
	{
		//printf("%d\n", n);
		fwrite(tmp, sizeof(char), n, ft);
	}
		
	fclose(fs);
	fclose(ft);
	return 0;
}
