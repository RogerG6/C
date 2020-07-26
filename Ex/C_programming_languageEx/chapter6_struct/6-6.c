/* Date��2020/3/16
 * 6-6���Ա��ڽ��ܵĺ���Ϊ��������дһ���ʺ�C����ʹ�õ�#define�������ļ򵥰汾(���޲������)����ᷢ��getch,ungetch�ǳ�����
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
#define MAXLEN	100
#define BUFSIZE 1000

struct nlist {
	struct nlist *next;	//ָ����һ��nlist 
	char *name;			//��������� 
	char *defn;			//�滻�ı� 
};

struct nlist *hashtab[HASHSIZE] = {NULL};
char *__strdup(char *s);
struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
unsigned hash(char *s);
void undef(char *name);
int getword(char *word, int lim);
void getdef(void);
void error(int c, char *s);
void skip_blank(void);
void ungets(char *s);
int getch(void); 
void ungetch(int c);
int comment(void);

main(void)
{
	char w[MAXLEN], defn[MAXLEN];
	struct nlist *p;
	
	while (getword(w, MAXLEN) != EOF){
		if (strcmp(w, "#") == 0)
			getdef();			//beginning of direct
		else if (!isalpha(w[0]))
			printf("%s", w);	//can't be defined
		else if ((p = lookup(w)) == NULL)
			printf("%s", w);	//not be defined
		else
			ungets(p->defn);	//push definition
	}

		
	return 0;
}

/* ��ȡ���� */ 
void getdef(void)
{
	char dir[MAXLEN], name[MAXLEN], def[MAXLEN];
	int i;
	
	skip_blank();
	if (!isalpha(getword(dir, MAXLEN)))
		error(dir[0], "getdef: expecting a directive after #");
	else if (strcmp(dir, "define") == 0)
	{
		if (!isalpha(getword(name, MAXLEN)))
			error(name[0], "getdef: non-alpha - name expected\n");
		else
		{
			skip_blank();
			for (i = 0; i < MAXLEN; i++)
				if ((def[i] = getch()) == EOF || def[i] == '\n')
					break;
			def[i] = '\0';
			if (i <= 0)
				error('\n', "getdef: incomplete define");
			else
				install(name, def);
		}
	}
	else if (strcmp(dir, "undef") == 0)
	{
		skip_blank();
		if (!isalpha(getword(name, MAXLEN)))
			error(name[0], "getdef: non-alpha in undef");
		else
			undef(name);
	}
	else
		error(dir[0], "getdef: expecting a directive after #");
}

void error(int c, char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n')
		c = getch();
}

void skip_blank(void)
{
	int c;
	while ((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
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

/* ���ַ�������hashval */ 
unsigned hash(char *s)
{
	unsigned hashval = 0;
	for (; *s; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* ���ַ�����hashtab�в����Ƿ����
 * ���ڷ���ָ��struct nlist��ָ��
 * ���򷵻�NULL */ 
struct nlist *lookup(char *s)
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
	{
		if (strcmp(s, np->name) == 0)
			return np;
	}
	//printf("lookup\n");
	return NULL;
}



/* ������name ���ı�defn ��ŵ�hashtab�� 
 * �ɹ�����ָ��struct nlist��ָ��
 * ���򷵻�NULL */ 
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	 
	if ((np = lookup(name)) == NULL)	//һ��ʼ�����ڸ�name 
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = __strdup(name)) == NULL)
			return NULL;		//����ʧ��
		hashval = hash(name);
		//printf("NULL? : %d\n", hashtab[hashval] == NULL);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else		//�ҵ�������
		free((void *)np->defn) ;	//�ͷ�ԭ��defnָ��Ŀռ� 
	if ((np->defn = __strdup(defn)) == NULL)
		return NULL;
	return np;
}

void undef(char *name)
{
	int cond;
	struct nlist *np, *pre = NULL;
	
	for (np = hashtab[hash(name)]; np != NULL; np = np->next)
		if (strcmp(name, np->name) == 0)
			break;
		else
			pre = np;
			
	if (pre == NULL)	//head
	{
		hashtab[hash(name)] = np->next;
	}
	else
	{
		pre->next = np->next;
	}
	free((struct nlist *)np);

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

void ungets(char *s)
{
	int n = strlen(s);
	while (n > 0)
		ungetch(s[--n]);
	
}
