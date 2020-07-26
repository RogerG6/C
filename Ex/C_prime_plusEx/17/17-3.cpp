# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "17-3.c"
void showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
	List movies;
	Item tmp;
	
	InitializeList(&movies) ;

	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available! Bye!\n");
		exit(1);
	}
		
	puts("Enter the first movie:");
	while (s_gets(tmp.title, TSIZE) != NULL && tmp.title[0] != '\0')
	{
		puts("Enter the rating <0-10>:");
		scanf("%d", &tmp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(tmp, &movies) == false)
		{
			fprintf(stderr, "Problem allocating memory\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			puts("The list is full now");
			break;
		}
		puts("Enter the next movie:");
	}
//	printf("Movie: %s	Rating: %d\n", movies.head->item.title, movies.head->item.rating);
	if (ListIsEmpty(&movies))
		printf("No data entered!\n");
	else
	{
		printf("Here is the movie list:\n");
		Traverse(&movies, showmovies);
	}
	//	puts("1");
	printf("You entered %d movies.\n", ListItemCount(&movies));
	
	EmptyTheList(&movies);
	puts("Bye!");
	
	return 0;
}

void showmovies(Item item)
{
	printf("Movie: %s	Rating: %d\n", item.title, item.rating);

}

char * s_gets(char *st, int n)
{
	char * ret, * find;
	ret = fgets(st, n, stdin);
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
