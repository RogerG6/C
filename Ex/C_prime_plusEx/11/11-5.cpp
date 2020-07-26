//strchr()和strnchr()的编写
# include <stdio.h> 
# include <ctype.h>
# include <string.h>
char * strchr( char * st, int c);
int strnchr(char *string, char *chr);

int main(void)
{
	char  st[81], chr[5];
	int c;
	
	puts("Press any key but q to continue, q to quit!");
	do
	{
		puts("Please enter your string！");
		fgets(st,81,stdin) ;
		puts("Please enter the seek alpha:");
		c = getchar();
//		fgets(chr, 5, stdin);
		
/*		c = strnchr(st, chr);
		if (-1 == c)
			printf("none!\n");
		else
			printf("here it is!\n");  */
		
		while (getchar() != '\n')
			;
	
		puts(strchr(st, c));
	}while (1); 
	return 0;
}

 char * strchr( char * st, int c)
{

	while (*st != '\0')
	{
		if (c == *st)
		{
		//	putchar('a');
			return st;
		}
		st++;
	}
	return NULL;
}

int strnchr(char *string, char *chr)   //查找字符串chr是否在字符串string中 
{
    int string_length = strlen(string);
    int chr_length = strlen(chr);
    int m = 0;
    int n = 0;

    for (size_t i = 0; i < string_length; i++)   //利用i, m, n来递增比指针方便 
    {
        n = i;
        m = 0;
        while (string[n] == chr[m])
        {
            n++;
            m++;
            if (m >= chr_length)
            {
                return i;
            }
        }
    }
    return -1;
}
