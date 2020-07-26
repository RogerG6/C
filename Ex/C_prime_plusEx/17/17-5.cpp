# include <stdio.h>
# include <string.h>
# include "stack.c"

char * s_gets(char *st, int n);

int main(void)
{
	Sta string;
	char tmp[SIZE];
	char c;
	
	InitializeSt(&string);
	puts("Enter a string:");
	if (s_gets(tmp, SIZE) != NULL && tmp[0] !='\0')
	{
		for (int i = 0; i < strlen(tmp); i++)
		{
			c = tmp[i];
			AddChar(c, &string);
		}
		ShowChar(&string);
	}
	printf("\nThere are %d chars.\n", StackCharCount(&string));

	
	puts("Bye!");
	return 0;
}

char * s_gets(char *st, int n)
{
	char * ret, * find;
	ret = fgets(st, n, stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
}
