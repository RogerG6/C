# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
	struct film * next;
}; 
char * s_gets(char *st, int n);
int showlist(struct film * f) ;

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];
	
	puts("Enter your first movie:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter the rating:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter your next movie:");
		prev = current;
	}
	
	puts("Here is head_to_tail list:");
	showlist(head);
	
	current = head;
	while (current != NULL)
	{
		head = current;
		free(current);
		current = head->next;
	}
	return 0;
}

int showlist(struct film * f) 
{
	struct film * tmp = f;    //确保递归返回时显示的是当前的结点 
	if (f->next == NULL)
	{
		printf("Movie: %s	Rating: %d\n", f->title, f->rating);
		puts("Here is tail_to_head list:");
		printf("Movie: %s	Rating: %d\n", f->title, f->rating);
		return 0;
	}
	else
	{
		printf("Movie: %s	Rating: %d\n", f->title, f->rating);
		f = f->next;
		showlist(f);
	}
	printf("Movie: %s	Rating: %d\n", tmp->title, tmp->rating);
	return 0;
}
char * s_gets(char * st, int n)
{
	char * ret, * find;
	ret = fgets(st, n ,stdin);
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret;
}
