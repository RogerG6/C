# include <stdio.h>
# include <ctype.h>
# include <string.h>
# define SEATS 12
# define LEN 20
char get_first(void);
int empty_n(struct seat * ps, int n);
int show_empty(struct seat * ps, int n);
int show_alpha(struct seat * ps, int n);
int assign(struct seat * ps, int n);
int del(struct seat * ps, int n); 

struct seat {
	char num;
	int flag;
	char fname[LEN];
	char lname[LEN];
};
int main(void)
{
	struct seat seat_info[SEATS];
	int ch;
	int i;
	int (*pf)(struct seat * ps, int n);
	//初始化座位信息 
	for (i = 0; i < SEATS; i++)
		seat_info[i].num = 'a' + i;
	for (i = 0; i < SEATS; i++)
	{	
		if (i % 3 == 0) 
		{
			seat_info[i].flag = 1;
			strcpy(seat_info[i].fname, "leno");
			strcpy(seat_info[i].lname, "paker");
		}
		else
		{
			seat_info[i].flag = 0;
			seat_info[i].fname[0] = '\0';
			seat_info[i].lname[0] = '\0';
		}
	}
	
	do
	{
		printf("To choose a function, enter its letter label:\n");
		printf("a) Show number of empty seats\n");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("E) Delete a seat assignment");
		puts("f) Quit");
		ch = get_first();
		switch(ch) 
		{
			case 'a' : pf = empty_n; break;
			case 'b' : pf = show_empty; break;
			case 'c' : pf = show_alpha; break;
			case 'd' : pf = assign; break;
			case 'e' : pf = del; break;
			case 'f' :break;
			default  :puts("Please enter a correct choice.");
		}	
		
		if (ch >= 'a' && ch <= 'e')
			(*pf)(seat_info, SEATS);
		
	}while (ch != 'f');
	
	
	return 0;
}

char get_first(void)
{
	char c;
	while ((isspace(c = getchar())))
		continue;
	while (getchar() != '\n')
		continue;
	return tolower(c);
}

int empty_n(struct seat * ps, int n)   //空座位计数 
{
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		if (ps[i].flag == 0)
			tot++;
	}
	return tot;
}

int show_empty(struct seat * ps, int n)   //显示空座位列表 
{
	for (int i = 0; i <n; i ++)
	{
		if (ps[i].flag == 0)
			printf("%c ", ps[i].num);
	}
	putchar('\n');
	return 0;
}

int show_alpha(struct seat * ps, int n)   //按字母表顺序显示座位 
{
	printf("flag = 0: empty\nflag = 1: occupied\n");
	for (int i = 0; i < n; i++)
	{
		if (ps[i].flag == 0)
			printf("编号：%c empty\n\n", ps[i].num);
		else
		{
			printf("编号：%c\n状态：%s\n", ps[i].num, (ps[i].flag ==  0) ? "empty" : "occupied");
			printf("姓名：%s %s\n\n", ps[i].fname, ps[i].lname);
		}
	}
	return 0;
}

int assign(struct seat * ps, int n)   //订座位 
{
	int ch, i;
	
	
	do
	{
		printf("Enter a seat choice you want to sit(# to quit): ");
		ch = get_first();
		
		for ( i = 0; i < n; i++)
		{
			if (ch == ps[i].num)
			{
				if (ps[i].flag == 0)
				{
					printf("Enter you name:");
					scanf("%s%s", &ps[i].fname, &ps[i].lname);
					ps[i].flag = 1;
					puts("Assignment done!");
					break;
				}
				else
				{
					printf("Please enter a right choice!\n");
					break;
				}
				break;
			}
		}
		if (i == n && ch != '#')
			printf("Please enter a right choice!\n");
	}while (ch != '#');
	return 0; 
}

int del(struct seat * ps, int n)  //取消订单 
{
	int ch, i;
	do
	{
		printf("Enter you seat number:");
		ch = get_first();
		for ( i = 0; i < n; i++)
		{
			if (ps[i].num == ch)
			{
				puts("Here is your information, if right press 'y', or press 'n' !");
				printf("编号：%c\n状态：%s\n", ps[i].num, (ps[i].flag ==  0) ? "empty" : "occupied");
				printf("姓名：%s %s\n", ps[i].fname, ps[i].lname);
				ch = get_first();
				if (ch == 'y')
				{
					ps[i].flag = 0;
					ps[i].fname[0] = '\0';
					ps[i].lname[0] = '\0';
					puts("Delete done!");
					break;
				}
				else
					break;
			}
		}
	}while (ch == 'n');
	return 0;
}
