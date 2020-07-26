# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char * argv[])
{
	char line[256];
	FILE * fp;
	
	if(argc != 3)
	{
		printf("Error, Usage: %s [character][file name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Cant open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(line, 256, fp) != NULL)     //��fgets, �����Ȳ���������ʱ���������з�Ϊֹ������line�� 
		if (strstr(line, argv[1]) != NULL)
			fputs(line,stdout);
	fclose(fp);
	
	return 0;
}
