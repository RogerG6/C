# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
	char ** p;
	int n_word;
	 char temp[256];
	
	printf("How many words do you wish to enter£¿ ");
	scanf("%d", &n_word) ;
	p = (char **)malloc(n_word * sizeof(char *));
	printf("Enter %d words now:\n", n_word);
	for (int i = 0; i < n_word; i++)
	{
		scanf("%s", temp);
		int len = strlen(temp) + 1;
		p[i] = (char *)malloc(len * sizeof(char));
		strcpy(p[i], temp);
	}
	for (int i = 0; i < n_word; i++)
	{
		printf("%s\n", p[i]);
		free(p[i]);
	}
	free(p);
	return 0;
}    

