/* Date：2020/3/15
 * 6-2：编写一个程序，用以读入一个C语言程序，并按字母表顺序分组打印变量名，要求每一组内各变量名的前6个字符相同
 *      其余字符不同。字符串和注释中的单词不予考虑。请将6作为一个可在命令行中设定的参数
 */ 

#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//#include <math.h>

#define BUFSIZE 100
#define MAXWORD 100

struct tnode {
	char *word;
	int cnt;
	struct tnode *left;
	struct tnode *right;
};

char tmp[MAXWORD];		//存储临时word 
int num;				//前n个字符 

void ungetch(int c);
int getch(void);
int getword(char *word, int lim);
struct tnode *addtree(struct tnode *p, char *w);
struct tnode *talloc(void);
void treeprint(struct tnode *p);
char *__strdup(char *s);
int issame(char *s1, char *s2);

int main(int argc, char *argv[])
{
	char word[MAXWORD];
	struct tnode *root = NULL;
	
	
	if (argc != 2) 
	{
		printf("Usage: *.exe n\n");
		return -1;
	}
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha((word[0])))
		{
			//printf("1\n");
			root = addtree(root, word);
			//printf("2\n");
		}
			
	num = atoi(argv[1]);
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
	}
	else if ((cond = strcmp(w, p->word)) == 0)
	{
		p->cnt++;
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
		
		if (!(cond = issame(p->word, tmp))) 
			putchar('\n');
		printf("%4d %s\n", p->cnt, p->word);
		strcpy(tmp, p->word);
		
		treeprint(p->right);
	}
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
