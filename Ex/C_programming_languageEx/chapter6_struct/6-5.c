/* Date��2020/3/15
 * 6-5: ��д����undef����������lookup��installά���ı���ɾ��һ�����������䶨��
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101
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


main(void)
{
	char name[100], defn[100];
	struct nlist *np;
	
	printf("Enter name, defname:");
	
	do
	{
		gets(name);
		gets(defn);
		install(name, defn);
	}while (name[0] != '#' && defn[0] != '#');
	
	do
	{
		printf("Enter name to find:");
		gets(name);
		printf("%s is%s in hashtab\n", name, (np = lookup(name)) == NULL ? " not" : " ");
		printf("defname = %s\n", np ? np->defn : "none");
	}while(name[0] != '#');
	
	// delete name and defname
	printf("delete defname\n");
	gets(name);
	undef(name);
	
	//check it is removed or not
	printf("check it is removed or not\n");
	gets(name);
	printf("%s is%s in hashtab\n", name, (np = lookup(name)) == NULL ? " not" : " ");
	printf("defname = %s\n", np ? np->defn : "none");
	
	return 0;
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
