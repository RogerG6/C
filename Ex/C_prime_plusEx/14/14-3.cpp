# include <stdio.h> 
# include <string.h>
# define MAXTITL 40
# define MAXAUTL 40
# define MAXBKS 100
char * s_gets(char * st, int n);
void show_ar(const struct book * ps, int n);
void sort_title(struct book * ps, int n);
void sort_value(struct book * ps, int n);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
static struct book tmp[MAXBKS];

int main(void)
{
	struct book library[MAXBKS]	;
	int ct = 0;
	int i;
	
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (ct < MAXBKS && s_gets(library[ct].title, MAXTITL) != NULL && library[ct].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[ct].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[ct++].value);
		while (getchar() != '\n')
			continue;
		if (ct < MAXBKS)
			printf("Enter the next title.\n");
	}
	
	if (ct > 0)
	{
		for (i = 0; i < ct; i++)
			tmp[i] = library[i];
		printf("Here is your list of books:\n")	;
		show_ar(library, ct);
		printf("Here is the list of your books in order of title:\n");
		sort_title(tmp, ct);
		show_ar(tmp, ct);
		printf("Here is the list of your books in order of value:\n");
		sort_value(tmp, ct);
		show_ar(tmp, ct);
	}	
	else
		printf("No books? Too bad.\n");

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;		
}

void show_ar(const struct book * ps, int n)   //显示数组内容 
{
	for (int i = 0; i < n; i++)
	{
		printf("%s by %s: $%.2f\n", ps[i].title, ps[i].author, ps[i].value);
	}
}

void sort_title(struct book * ps, int n)   //按标题首字母降序排列 
{
	struct book tmp;
	for (int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
		{
			if (ps[i].title[0] < ps[j].title[0]) 
			{
				tmp = ps[i];
				ps[i] = ps[j];
				ps[j] = tmp;
			}
		}
}

void sort_value(struct book * ps, int n)   //按价格升序排列 
{
	struct book tmp;
	for (int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
		{
			if (ps[i].value > ps[j].value) 
			{
				tmp = ps[i];
				ps[i] = ps[j];
				ps[j] = tmp;
			}
		}	
}
