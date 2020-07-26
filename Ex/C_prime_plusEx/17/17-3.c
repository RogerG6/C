# include <stdio.h>
# include <stdlib.h>
# include "17-3list.h"

static void CopyToItem(Item item, List * pl);

void InitializeList(List * pl)
{
	(*pl).items = 0;
}

bool ListIsEmpty(List * pl)
{
	if ((*pl).items == 0)
		return true;
	else 
		return false;
}

bool ListIsFull(List * pl)
{
	if ((*pl).items == MAXSIZE)
		return true;
	else
		return false;
}

unsigned int ListItemCount(List * pl)
{
	return (*pl).items;
}

bool AddItem(Item item, List * pl)
{
	int n = (*pl).items;
	if (MAXSIZE == n)
		return false;
	(*pl).entries[n] = item;
	(*pl).items++;
	return true;
}

void Traverse(List * pl, void (*pfun)(Item item))
{
	int i;
	for (i = 0; i < (*pl).items; i++)
		(*pfun)((*pl).entries[i]);
}

void EmptyTheList(List * pl)
{
	(*pl).items = 0;
}

