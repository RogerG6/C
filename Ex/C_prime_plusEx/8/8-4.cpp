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
		if (isalpha(ch) && i ==1) // ������ 
			alpha++;
		if (isalpha(ch) && i == 0)  //���ʿ�ʼ 
		{
			i = 1;
			alpha++;
		}
		if ((isspace(ch) || ispunct(ch)) && i ==1)  //����ĩβ 
			{
				i = 0;
				n_word++;
			}
		 
		if ((isspace(ch) || ispunct(ch)) && i == 0) //���ڵ����� 
			continue;
		
		
		
	}
	printf("\n��%d����ĸ����%d�����ʣ�ƽ��ÿ��������%f����ĸ��\n", alpha, n_word, (float)alpha/n_word);
	
	return 0;
}
