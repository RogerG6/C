# include <stdio.h>
# include <ctype.h>

int  main(void)
{
	int ch; 
	int next;
	int alpha = 0, n_word = 0;
	int i = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch) && i ==1) // 单词中 
			alpha++;
		if (isalpha(ch) && i == 0)  //单词开始 
		{
			i = 1;
			alpha++;
		}
		if ((isspace(ch) || ispunct(ch)) && i ==1)  //单词末尾 
			{
				i = 0;
				n_word++;
			}
		 
		if ((isspace(ch) || ispunct(ch)) && i == 0) //不在单词中 
			continue;
		
		
		
	}
	printf("\n有%d个字母，有%d个单词，平均每个单词有%f个字母！\n", alpha, n_word, (float)alpha/n_word);
	
	return 0;
}
