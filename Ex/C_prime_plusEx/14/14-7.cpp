# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAXTITL 40
# define MAXAUTL 40
# define MAXBKS 10
char * s_gets(char * st, int n);
void show_stct(struct book * ps, int n);
void del_book(struct book * ps, int n);
void change_book(struct book * ps, int n);

struct book {
	int flag;
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	FILE * fp;
	int i, filecount;
	int size = sizeof(struct book);
	
	if ((fp = fopen("book.txt", "a + b")) == NULL)
	{
		printf("Cant open file\n");
		exit(1);
	}
	
	rewind(fp);
	while (count < MAXBKS && (fread(&library[count], size, 1, fp) == 1))
	{
		if (count == 0)
			puts("Current contents of book.txt:");
		if (library[count].flag == 1)
		{
			printf("(flag: %d)%s by %s: $%.2f\n", library[count].flag, library[count].title, library[count].author, library[count].value);
			count++;
		}	
	}
	filecount = count;
	if (count == MAXBKS)
	{
		printf("The book.txt file is full.\n");
		exit(2);
	}
	
	puts("Please add new book titles.");
	puts("Press [ENTER] at the start of a line to stop.");
	for (int i = 0; i < MAXBKS; i++)
	{
		if (library[i].flag == 0)
		{
			if (s_gets(library[i].title, MAXTITL) != NULL && library[i].title[0] != '\0')
			{
				puts("Now enter the author.");
				s_gets(library[i].author, MAXAUTL) ;
				puts("Now enter the value.");
				scanf("%f", &library[i].value);
				puts("Now enter the state. FLAG");
				scanf("%d", &library[i].flag);
				while (getchar() != '\n')
					continue;
				count++;
				puts("Enter the next title.");
			}
			else
				goto part1;
		}
	}
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL) ;
		puts("Now enter the value.");
		scanf("%f", &library[count].value);
		puts("Now enter the state.");
		scanf("%d", &library[count++].flag);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			puts("Enter the next title.");
	}
	
	part1: if (count > 0)
	{
		show_stct(library, count);
		fwrite(&library[filecount], size, count - filecount, fp);
	}
	else
		puts("No books? Too bad.");
		
	fclose(fp);
	
	if ((fp = fopen("book.txt", "r+b")) == NULL)
	{
		printf("Cant open file\n");
		exit(1);
	}
		
	del_book(library, count);
	rewind(fp);
	fwrite(library, size, count, fp);
	
	change_book(library, count);
	rewind(fp);
	fwrite(library, size, count, fp);
		
	fclose(fp);
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

void del_book(struct book * ps, int n)
{
	int i;
	char bkname[40];
	
	do
	{
		puts("Enter the name of book you want to delete.");
		s_gets(bkname, 40);
		for ( i = 0; i < n; i++)
		{
			if (strcmp(bkname, ps[i].title) == 0)
			{
				ps[i].title[0] = '\0';
				ps[i].author[0] = '\0';
				ps[i].value = 0;
				break;
			}
		}
		if (i == n)
			puts("Enter the right book name.");
	}while (i == n);
}

void change_book(struct book * ps, int n)
{
	int i;
	char bkname[40];
	
	do
	{
		puts("Enter the name of book you want to change.");
		s_gets(bkname, 40);
		for ( i = 0; i < n; i++)
		{
			if (strcmp(bkname, ps[i].title) == 0)
			{
				puts("Enter the book title.");
				s_gets(ps[i].title, MAXTITL);
				puts("Enter the author.");
				s_gets(ps[i].author, MAXAUTL);
				puts("Enter the value.");
				scanf("%f", &ps[i].value);
				while (getchar() != '\n')
					continue;
				break;
			}
		}
		if (i == n)
			puts("Enter the right book name.");
	}while (i == n);
}

void show_stct(struct book * ps, int n)
{
	for (int i = 0; i < n; i++)
		printf("(flag: %d)%s by %s: $%.2f\n", ps[i].flag, ps[i].title, ps[i].author, ps[i].value);
}
