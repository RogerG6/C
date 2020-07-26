# include <stdio.h>
# include <ctype.h>
# include "17-7.c"
# define NAME 20

void showmenu(void);
char * s_gets(char *st, int n);


int main(void)
{
	Tree words;
	char flname[NAME];
	FILE * fp;
	char tmp[LEN];
	int ch;
	int i = 0;
	
	InitializeTree(&words);
	puts("Enter the file name:");
	s_gets(flname, NAME);

	if ((fp = fopen(flname, "rb")) == NULL)
	{
		puts("fail to open file");
		exit(1);
	}
	
	while ((ch = getc(fp)) != EOF)
	{	
		i = 0;
		if (isalpha(ch))    //以二进制模式打开文本，行尾是\r\n,而文本则是\n, 所以需判断这一步；两个word中间有两个以上的非字母字符也需要判断 
		{
			while (isalpha(ch))
			{
				tmp[i] = ch;
				i++;
				ch = getc(fp);
	//			printf("%d", i);
			}
	//		putchar('\n');
			tmp[i] = '\0';
			
			AddItem(tmp, &words);
		}
		
	}
	
	showmenu();
	while (scanf("%d", &ch) != 1 || ch >3 ||ch < 1)
		continue;
	while (getchar()!= '\n')
		continue;
	while (ch != 3)
	{
		switch (ch)
		{
			case 1:	show_word_times(&words, show_w_t); break;
			case 2: s_gets(tmp, LEN); print_times(&words, tmp); break;
			case 3: goto end;
		}
		puts("Enter your choice:");
		while (scanf("%d", &ch) != 1 || ch >3 ||ch < 1)
			continue;
		while (getchar()!= '\n')
			continue;
	}
	
	end: EmptyTree(&words);
	
	return 0;
}

void showmenu(void)
{
	puts("1) display all words and its times");
	puts("2) enter a word, program will show the appear times in file");
	puts("3) press q to quit");
	printf("Now enter your choice:");
}

char * s_gets(char *st, int n)
{
	puts("Enter a string name:");
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


