/* Date：2020/3/15
 * 6-4：编写一个程序，根据单词出现的频率按降序打印输入的各个不同的单词，并在每个单词的前面标上它出现的次数
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
	struct tnode *next;
};

char tmp[MAXWORD];		//存储临时word 
int num;				//前n个字符 

struct tnode *head;		//链表头指针 

void ungetch(int c);
int getch(void);
int getword(char *word, int lim);
struct tnode *addtree(struct tnode *p, char *w);
struct tnode *talloc(void);
void treeprint(struct tnode *p);
char *__strdup(char *s);
int issame(char *s1, char *s2);
void insert(struct tnode *newp);
void printlist(struct tnode *phead);
void sort_by_cnt(struct tnode *root); 

int main(int argc, char *argv[])
{
	char word[MAXWORD];
	struct tnode *root = NULL;
	
	
	if (argc != 1) 
	{
		printf("Usage: *.exe \n");
		return -1;
	}
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha((word[0])))
		{
			//printf("1\n");
			root = addtree(root, word);
			//printf("2\n");
		}
	sort_by_cnt(root);
	printlist(head);
		
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

void sort_by_cnt(struct tnode *root) 
{
	struct tnode *pt = root;
	
	if (pt != NULL)
	{
		sort_by_cnt(pt->left);
		insert(pt);
		sort_by_cnt(pt->right);
		
	}
}

void insert(struct tnode *newp)
{
	struct tnode *cur = head, *pre = head;
	
	if (cur == NULL)		//empty list
	{
		head = newp;
		newp->next = NULL;
	}
	else
	{
		while (cur != NULL && newp->cnt < cur->cnt)
		{
			pre = cur;
			cur = cur->next;		
		}
		
		if (cur == head)		//bigger than 1st		
		{
			head = newp;
			newp->next = cur;
		}
		else if (cur == NULL)   //smaller than last one
		{
			pre->next = newp;
			newp->next = NULL;	//in middle
		}
		else
		{
			pre->next = newp;
			newp->next = cur;
		}
	}
}

void printlist(struct tnode *phead)
{
	struct tnode *p = phead;
	
	while (p != NULL)
	{
		printf("%4d %s\n", p->cnt, p->word);
		p = p->next;
	}
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
