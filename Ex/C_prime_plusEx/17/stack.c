# include <stdio.h>
# include <stdlib.h>
# include "stack.h"

void InitializeSt(Sta * pst)  //��ʼ��
{
	pst->head = NULL;
	pst->end = NULL;
	pst->num = 0;
}

bool StackIsEmpty(Sta * pst)
{
	if (pst->num == 0)
		return true;
	else 
	 	return false;
}

bool StackIsFull(Sta * pst)
{
	if (pst->num == SIZE)
		return true;
	else
		return false;
}

int StackCharCount(Sta * pst)
{
	return pst->num;
}

bool AddChar(char ch, Sta * pst)   //����һ��Ԫ��
{
	if (StackIsFull(pst))
	{
		puts("Stack is full now.");
		return false;
	}
	
	Node * pnew;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		printf("problem in allocating memory\n");
		return false;
	}
	pnew->ch = ch;
	pnew->next = NULL;
	if (StackIsEmpty(pst))
	{
		pst->head = pnew;
		pst->end = pnew;
		pnew->pre = NULL;
	}
	else
	{
		pst->end->next = pnew;
		pnew->pre = pst->end;
		pst->end = pnew;
	}
	pst->num++;
}

void ShowChar(Sta * pst)  //��ջ����ʾ�ַ� 
{
	Node * psave, * current;
	current = pst->end;

	while (current != NULL)
	{
		putchar(current->ch);
		psave = current;
		free(current);
		current = psave->pre;
	}
}
