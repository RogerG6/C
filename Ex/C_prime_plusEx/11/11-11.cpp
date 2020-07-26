# include <stdio.h> 
# include <string.h>
# include <ctype.h>
# define LEN 81
# define LIM 3
int s_gets(char * st, int n);
void show_s(char st[][LEN], int lim);
void show_asc(char st[][LEN], int lim);
void show_lenup(char st[][LEN], int lim);
void show_fwordl(char st[][LEN], int lim);
int fword_len(char * st);
char char_get(void);

int main (void)
{
	char str[LIM][LEN];
	int i, c, ret;
	

		i = 0;
		printf("Enter %d strings!\n", LIM);
		while (i < LIM )
		{
			ret = s_gets(*(str + i), LEN);
		//	printf("%d\n", ret);
			if (str[i][0] == '\0')   
				break;
		//	putchar(*ret);
			i++;
		}
					
	do
	{
		puts("There are 5 choice you can choice! Press e to quit!");
		printf("---------------------------------------------------------------\n");
		printf("a. 打印原字符串列表                b. 以ASCII码顺序打印字符串\n");
		printf("c. 按长度递增打印字符串            d. 按字符串第一个单词长度打印字符串\n");
		printf("e. 退出\n") ;
		printf("---------------------------------------------------------------\n");
		

		switch (c = char_get())
		{
			case 'a': show_s(str, LIM);
					  break;
			case 'b': show_asc(str, LIM);
					  break;
			case 'c': show_lenup(str,LIM);
					  break;
			case 'd': show_fwordl(str, LIM);
					  break;
			case 'e': break;
			default : puts("Give a right choice!!!");
					  break;
		}	
	} while (c != 'e');
	
	
	return 0;
}

int  s_gets(char * st, int n)   //read string
{
	int  ret_val = 1;
	
	fgets(st, n, stdin);
	while (*st != '\n' && *st != '\0' )
	{
//		putchar(*st);
		if (*st == EOF)  //EOF实现不了 
		{
//			puts("a");
			return 0;
		}
		st++;
	}	
	if (*st == '\n')
		*st = '\0';
	else 
		while (getchar() != '\n')	
			continue;
	return ret_val;
}

void show_s(char st[][LEN], int lim)  //print string
{
	int i = 0;
	
	while (i < lim)
		puts(*(st + i++));
}

void show_asc(char st[][LEN], int lim)  //printf string with ASCII order
{
	char tem[LEN];
	int i, j ;
	
	for (i = 0; i <= lim - 2; i++)
		for (j = i + 1; j < lim; j++)
		{
			if (**(st + i) > **(st + j))
			{
				strcpy(tem, *(st + i));
				strcpy(*(st + i), *(st + j));
				strcpy(*(st + j), tem);
			}
		}
	show_s(st, lim);
}

void show_lenup(char st[][LEN], int lim)  //show string as length up order
{
	char tem[LEN];
	int i, j ;
	
	for (i = 0; i <= lim - 2; i++)
		for (j = i + 1; j < lim; j++)
		{
			if (strlen(*(st + i)) > strlen(*(st + j)))
			{
				strcpy(tem, *(st + i));
				strcpy(*(st + i), *(st + j));
				strcpy(*(st + j), tem);
			}
		}
	show_s(st, lim);
}

void show_fwordl(char st[][LEN], int lim)  //show string as first word's length
{
	char tem[LEN];
	int i, j ;
	
	for (i = 0; i <= lim - 2; i++)
		for (j = i + 1; j < lim; j++)
		{
			if (fword_len(*(st + i)) > fword_len(*(st + j)))
			{
				strcpy(tem, *(st + i));
				strcpy(*(st + i), *(st + j));
				strcpy(*(st + j), tem);
			}
		}
	show_s(st, lim);
}

int fword_len(char * st)    //count string's first word's length
{
	int n = 0;
	
	while (! isalpha(*st))
		st++;
	
	do
	{
		n++;
		st++;	
	} while (isalpha(*st));
	
	return n;
}

char char_get(void)   //only read first char
{
	int c;
	c = getchar();
	while (getchar() != '\n')
		continue;
	
	return c;
}





