# include <stdio.h> 
# include <ctype.h>

char get_first(void);

int main(void)
{
	printf("%c\n", get_first());
	
	return 0;
}
char get_first(void) 
{
	int ch;
	
	while (isspace(ch = getchar()))  //跳过所有空白符 
		continue;
	while (getchar() != '\n')  //只取首字符 
		continue;
		
	return ch; 
}
