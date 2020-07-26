# include <stdio.h> 
# include <ctype.h>
int main(void)
{
	int word = 0, up = 0, low = 0, punct = 0, digit = 0, inword = 0, c;
	while ((c = getchar()) != EOF)
	{
		if (isalpha(c) && inword == 0)
		{
			word++;
			inword = 1;	
		}
		if (! (isalpha(c)) && inword==1)
			inword =0;
		if (isupper(c))
			up++;
		if (islower(c))
			low++;
		if (ispunct(c))
			punct++;
		if (isdigit(c))
			digit++;
	
	}
	printf("word = %d, upper = %d, lower = %d, punct = %d, digit = %d\n", word, up, low, punct, digit);
	
	return 0;
}


