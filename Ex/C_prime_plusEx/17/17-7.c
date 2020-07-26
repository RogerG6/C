# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "17-7tree.h"
# define MAXWORD 100

typedef struct pair {
	Trnode * parent;
	Trnode * child;
}Pair;
static Pair SeekItem(char * pi, Tree * ptree);
static bool ToLeft(char * st1, char * st2);
static bool ToRight(char * st1, char * st2);
static void AddNode(Trnode * pnew, Trnode * root);
static Trnode * MakeNode(char * st);
static void DelAllNodes(Trnode * root);
static void InOrder(Trnode * root, void (*pfun)(Trnode * pnode));

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else 
		return false;
}

bool TreeIsFull(Tree * ptree)
{
	if (ptree->size == MAXWORD)
		return true;
	else
		return false;
}

bool AddItem(char * pi, Tree * ptree)
{
	Pair find;
	Trnode * pnew;
	find = SeekItem(pi, ptree);
	if (find.child != NULL)
	{
		find.child->ct++;
		return true;
	}
	else
	{
//		puts("1");
		pnew = MakeNode(pi);
	
		if (pnew == NULL)
		{
			printf("allocating memory error");
			return false;
		}
	
		ptree->size++;
		
		if (ptree->root == NULL)
			ptree->root = pnew;
		else
			AddNode(pnew, ptree->root);	
	}
//	printf("%s\n", pnew->word);
	return true;
	
}

static Pair SeekItem(char * pi, Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	
	if (look.child == NULL)	
		return look;
	
	while (look.child != NULL)
	{
		if (ToLeft(pi, look.child->word))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, look.child->word))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

void EmptyTree(Tree * ptree)
{
	if (ptree != NULL)
		DelAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static bool ToLeft(char * st1, char * st2)
{
	if (strcmp(st1, st2) < 0)
		return true;
	else
		return false;
}

static bool ToRight(char * st1, char * st2)
{
	if (strcmp(st1, st2) > 0)
		return true;
	else
		return false;
}

static void DelAllNodes(Trnode * root)
{
	Trnode * pright;
	
	if (root != NULL)
	{
		pright = root->right;
		DelAllNodes(root->left);
		free(root);
		DelAllNodes(pright);
	}
}

static void AddNode(Trnode * pnew, Trnode * root)
{
	if (ToLeft(pnew->word, root->word))
	{
		if (root->left == NULL)
			root->left = pnew;
		else
			AddNode(pnew, root->left);
	}
	else 
	{
		if (root->right == NULL )
			root->right = pnew;
		else
			AddNode(pnew, root->right);
	}
}

static Trnode * MakeNode(char * st)
{
	Trnode * pnew;
	pnew = (Trnode *)malloc(sizeof(Trnode));
	
	if (pnew != NULL)
	{
		strcpy(pnew->word, st);
		pnew->ct = 1;
		pnew->left = NULL;
		pnew->right = NULL;
	}
	return pnew;
	
}

void Traverse(Tree * ptree, void (*pfun)(Trnode * pnode))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

static void InOrder(Trnode * root, void (*pfun)(Trnode * pnode))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root);
		InOrder(root->right, pfun);
	}
}

static void show_w_t(Trnode * pnode)
{
	printf("Word: %-10s	times: %d\n", pnode->word, pnode->ct);
}

void show_word_times(Tree * ptree, void (*pfun)(Trnode * pnode))   //function 1
{
	Traverse(ptree, show_w_t);
}

void print_times(Tree * ptree, char * st)    //function 2
{
	Pair find;
	
	find = SeekItem(st, ptree);
	if (find.child != NULL)
		printf("Word: %s	times: %d\n", find.child->word, find.child->ct);
	else
		puts("No this word in tree!");
}


