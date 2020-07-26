# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define TSIZE 45

struct film {
	struct film * up;
	char title[TSIZE];
	int rating;
	struct film * down;
};

char * s_gets(char * st, int n);

int main(void)
{
	struct film * head, * tail;
	struct film * prev, * current, * next;
	char input[TSIZE];
	int num = 0; 
	
	head = tail;
	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if (num == 0)
		{
			head = current;
			current->down = NULL;
			tail = current;
			current->up = NULL;
			
		}
		else
		{
			prev->down = current;
			current->down = NULL;
			tail = current;
			current->up = prev; 
		}
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
			continue;
		puts("Enter your next movie title (empty line to quit):");
		prev = current;
		num++;
	}
	
	//show table
	if (num == 0)
		printf("No data entered.\n");
	else 
		printf("Here is the head_to_tail movie list:\n");
	current = head;
	int n = num;
	while (n-- != 0)   //正向显示 
	{
		printf("Movie: %s	Rating: %d\n", current->title, current->rating);
		current = current->down;
	}
	printf("Here is the tail_to_head movie list:\n");
	current = tail;
	n= num;
	while (n-- != 0)   //反向显示 
	{
		printf("Movie: %s	Rating: %d\n", current->title, current->rating);
		current = current->up;
	}
	
	current = head;    //释放内存 
	n = num;
	while (n-- != 0) 
	{
		free(current);
		current = head->down;
		head = current;
	}

	
	return 0;
}

char * s_gets(char * st, int n) 
{
	char * ret, * find;
	
	ret = fgets(st, n, stdin) ;
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
