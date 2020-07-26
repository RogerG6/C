/* Date：2020/3/12 
 * 6-1：上述getword函数不能正确处理下划线、字符串常量、注释及预处理器控制指令。请编写一个更完善的getword函数
 */ 
#include <stdio.h> 
#include <ctype.h>
#include <string.h>

struct key {
	char *word;
	int cnt;
}keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0, 
	"volatile", 0,
	"while", 0
};

#define BUFSIZE 100
#define MAXWORD 100
#define NKEYS	(sizeof(keytab) / sizeof(keytab[0]))

void ungetch(int c);
int getch(void);
int binsearch(char *word, struct key tab[], int n);
int getword(char *word, int lim);


main()
{
	int i, n;
	char word[MAXWORD];
	
	while(getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]))
		{
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
			{
				keytab[n].cnt++;			
			}
			printf("word = %s, nkeys = %d, n = %d\n", word, NKEYS, n);					
		}
	}

			
	for (i = 0; i < NKEYS; i++)
		printf("%s = %d\n", keytab[i].word, keytab[i].cnt);
	
	return 0;
}

int getword(char *word, int lim)
{
	char *w = word;
	int c, d;
	
	while (isspace(c = getch()))
		;
		
	if (c != EOF)
		*w++ = c;
	
	if (isalpha(c) || c == '_' || c == '#')
	{
		for (; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_')
			{
				ungetch(*w);
				break;
			}
	}
	else if (c == '\'' || c == '"')	
		for (; --lim > 0; w++)
		{
			if ((*w = getch()) == '\\')
				*++w = getch();
			else if (*w == c)
			{
				w++;
				break;
			}
			else if (*w == EOF)
				break;
			//printf("In getword: word = %s\n", word);
		}
		
	
	else if (c == '/')
		if ((d = getch()) == '*')
			c = comment();
		else
			ungetch(d);
	
	*w = '\0';
	printf("In getword: word = %s\n", word);
	return c;
}

int comment(void)
{
	int c;
	
	while ((c = getch()) != EOF)
	{
		if (c == '*')
			if  ((c = getch()) == '/')
				break;
			else
				ungetch(c) ;		
	}
	
	return c;
}

int binsearch(char *word, struct key tab[], int n)
{
	int cond, mid;
	
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}


int buf[BUFSIZE];
int bufp = 0; 

int getch(void)
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("error: buf is full\n");
	else
		buf[bufp++] = c;
}
