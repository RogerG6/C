# include <stdio.h>

int main(int argc, char *argv[])
{
	int ct;
	
	for (ct = argc - 1; ct > 0; ct-- )
		printf("%s ", argv[ct]);
	putchar('\n');
	
	return 0;
}


