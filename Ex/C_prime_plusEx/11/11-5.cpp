//strchr()��strnchr()�ı�д
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
		puts("Please enter your string��");
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

int strnchr(char *string, char *chr)   //�����ַ���chr�Ƿ����ַ���string�� 
{
    int string_length = strlen(string);
    int chr_length = strlen(chr);
    int m = 0;
    int n = 0;

    for (size_t i = 0; i < string_length; i++)   //����i, m, n��������ָ�뷽�� 
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
