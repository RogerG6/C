/* Date：2020/3/15
 * 6-3：编写一个交叉引用程序，打印文档中所有单词的列表，并且每个单词还有一个列表，记录出现过该单词的行号。
 *   	 对the, and等实义单词不予考虑
 */ 

#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>

#define BUFSIZE 100
#define MAXWORD 100
#define MAXFREQ 10000

struct tnode {
	char *word;
	int cnt;
	int line[MAXFREQ];
	struct tnode *left;
	struct tnode *right;
};

char tmp[MAXWORD];		//存储临时word 
int num;				//前n个字符 
int line = 1;			//行号 

void ungetch(int c);
int getch(void);
int getword(char *word, int lim);
struct tnode *addtree(struct tnode *p, char *w);
struct tnode *talloc(void);
void treeprint(struct tnode *p);
char *__strdup(char *s);
int issame(char *s1, char *s2);
void printlinenum(int *line, int n);
int is_no_mean_word(char *s);

int main(int argc, char *argv[])
{
	char word[MAXWORD];
	struct tnode *root = NULL;
	int c;
	
	if (argc != 1) 
	{
		printf("Usage: *.exe\n");
		return -1;
	}
	
	while ((c = getword(word, MAXWORD)) != EOF)
	{
		if (c == '\n')
		{
			//printf("new line\n");
			line++;
			continue;
		}
		if (isalpha((word[0])))
		{
			//printf("1\n");
			root = addtree(root, word);
			//printf("2\n");
		}		
	}
		
			
	//num = atoi(argv[1]);
	//printf("num = %d\n", num);
	treeprint(root);
	
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	//printf("3\n");
	if (p == NULL)
	{
		p = talloc();
		if (p == NULL)
		{
			printf("error: can't alloc memory\n");
			return NULL;
		}
		p->word = __strdup(w);
		p->cnt = 1;
		p->left = NULL;
		p->right = NULL; 
		p->line[p->cnt - 1] = line;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->cnt++;
		p->line[p->cnt - 1] = line;
	}
		
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

struct tnode *talloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}

char *__strdup(char *s)
{
	char *p = malloc(strlen(s) + 1);
	
	if (p == NULL)
	{
		printf("error: can't alloc memory for string\n");
		return NULL;
	}
	strcpy(p, s);
	return p;
}

void treeprint(struct tnode *p)
{
	int cond;
	
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->cnt, p->word);
		if (!is_no_mean_word(p->word))
			printlinenum(p->line, p->cnt);
		treeprint(p->right);
	}
}

int is_no_mean_word(char *s)
{
	if (!strcmp(s, "the"))
		return 1;
	if (!strcmp(s, "and"))
		return 1;
		
	return 0;
}

void printlinenum(int *line, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("\tline %d\n", line[i]);
}

/* 判断前num个字符是否一样 */ 
int issame(char *s1, char *s2)
{
	int i;
	for (i = 0; i < num && s1[i] && s2[i] && s1[i] == s2[i]; i++)
		;
		
	if (i == num)
		return 1;
	else
		return 0;
}

int getword(char *word, int lim)
{
	char *w = word;
	int c, d;
	
	while (isspace(c = getch()))
		if (c == '\n')
			return c;
		
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
	//printf("In getword: word = %s\n", word);
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
