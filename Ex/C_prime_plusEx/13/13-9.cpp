# include <stdio.h>
# include <stdlib.h>
# define MAX 41
int main(void)
{
	FILE * fp;
	int ct = 0, ch;
	char word[MAX];
	
	if ((fp = fopen("wordy.txt", "a+")) == NULL)
	{
		printf("Cant open \"wordy\" file\n");
		exit(EXIT_FAILURE);
	}
	
	while (fgets(word, MAX, fp) != NULL)
		ct++;
	rewind(fp);
	
	puts("Enter words to add to the file; press the # key at the beginning of a line to terminate.");
	while ((scanf("%40s", word) == 1) && (word[0] != '#'))
		fprintf(fp, "%d.%s\n", ++ct, word);
	
	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%s", word) == 1)
		printf("%s\n", word);   //加一个ct计数即可 
	puts("Done!");
	if (fclose(fp) != 0)
		printf("Error in closing file\n");
		
	return 0;
}
