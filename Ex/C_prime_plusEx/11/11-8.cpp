# include <stdio.h>
# include <string.h>
char * string_in(char * st1, char * st2);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[81];
	char str2[81];
	
	do
	{
		puts("Enter string 1:");
		s_gets(str1, 81);
		puts("Enter string 2:");
		s_gets(str2, 81);
		
		puts(string_in(str1, str2));
		
		puts("Press enter to continue, q to quit!");
	} while (getchar() != 'q');
	
	return 0;
}

char * string_in(char * st1, char * st2)
{
  	int string_length = strlen(st1);
    int chr_length = strlen(st2);
    int m = 0;
    int n = 0;

    for (size_t i = 0; i < string_length; i++)   //利用i, m, n来递增比指针方便 
    {
        n = i;
        m = 0;
        while (st1[n] == st2[m])
        {
            n++;
            m++;
            if (m >= chr_length)      //先判断是否到末尾，后比较 
            {
                return st1+i;
            }
        }
    }
    return NULL;
}

/*
char * string_in(const char * s1, const char * s2)
{
	int l2 = strlen(s2);
	int tries;            // maximum number of comparisons    //如果s2比s1长，则没必要比较 
	int nomatch = 1;      // set to 0 if match is found 
	tries = strlen(s1) + 1 - l2;
	if (tries > 0)
		while (( nomatch = strncmp(s1, s2, l2)) && tries--)
			s1++;
	if (nomatch)
		return NULL;
	else
		return (char *) s1; //cast const away 
}
*/

char * s_gets(char * st, int n)
{
	char * ret_val;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
			while (*st != '\n' && *st != '\0')
				st++;
			if (*st == '\n')
				*st = '\0';
			else
				while (getchar() != '\n')
					continue;
	}

	return ret_val;
}
