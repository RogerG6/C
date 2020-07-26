# include <stdio.h>
# include <stdlib.h>
# include "17-2list.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List * lb)
{
	lb->head = NULL;
	(*lb).end = NULL;
	
}

bool ListIsEmpty(List * lb)
{
	if ((*lb).head == NULL)
		return true;
	else 
		return false;
}

bool ListIsFull(List * lb)
{
	Node * pt;
	bool full;
	
	pt = (Node * )malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else 
		full = false;
	free(pt);
	return full;
}

unsigned int ListItemCount(List * lb)
{
	unsigned int num = 0;
	Node * pt;
	pt = (*lb).head;
	while (pt != NULL)
	{
		++num;
		pt = pt->next;
	}
	return num;
}

bool AddItem(Item item, List * lb)
{
	Node * pnew;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;
	CopyToNode(item, pnew);
	pnew->next = NULL;
//	printf("Movie: %s	Rating: %d\n", pnew->item.title, pnew->item.rating);
	if (NULL == (*lb).head)
	{	
//		puts("1");
		(*lb).head = pnew;
		(*lb).end = pnew;
	}
	else
	{
		(*lb).end->next = pnew;
		(*lb).end = pnew;
	}
//	printf("Movie: %s	Rating: %d\n", (lb.head)->item.title, (lb.head)->item.rating);
	return true;
}

void Traverse(List * lb, void(*pfun)(Item item))
{
	Node * pnode = (*lb).head;
	
	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List * lb)
{
	Node * psave, * current;
	current = (*lb).head;
	psave = current;
	while (current != NULL)
	{
		psave = psave->next;
		free(current);
		current = psave;
	}
}

static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
