# include <stdio.h>
# include <ctype.h>
# include <string.h>
# define SEATS 12
# define LEN 20 
# define FLHTNUM 4
int flight_code[4] = {102, 311, 444, 519};
char get_first(void);
int empty_n(struct seat * ps, int n);
int show_empty(struct seat * ps, int n);
int show_alpha(struct seat * ps, int n);
int assign(struct seat * ps, int n);
int ak_assign_seat(struct seat * ps, int n);
int del(struct seat * ps, int n); 

struct seat {
	char num;
	int flag;
	char fname[LEN];
	char lname[LEN];
};
struct flight {
	int flight_num;
	struct seat seat_info[SEATS];
};
int main(void)
{
	struct flight flight_info[FLHTNUM];
	
	int ch;
	int i, j, fn;
	int (*pf)(struct seat * ps, int n);
	
	//初始化各班次座位信息 
	for (i = 0; i < FLHTNUM; i++)
	{
		flight_info[i].flight_num = flight_code[i];
		for (j = 0; j < SEATS; j++)
		{
			flight_info[i].seat_info[j].num = 'A' + j;
			if ((j + 1) % (i + 2) == 0) 
			{
				flight_info[i].seat_info[j].flag = 1;
				strcpy(flight_info[i].seat_info[j].fname, "leno");
				strcpy(flight_info[i].seat_info[j].lname, "paker");
			}
			else
			{
				flight_info[i].seat_info[j].flag = 0;
				flight_info[i].seat_info[j].fname[0] = '\0';
				flight_info[i].seat_info[j].lname[0] = '\0';
			}
		}
	}
	
	do
	{
		printf("Flights: %d %d %d %d\n", flight_code[0], flight_code[1], flight_code[2], flight_code[3]);
		puts("To choose a flight, enter the flight number:");
		if (scanf("%d", &fn) != 1)
		{
			while (getchar() != '\n')
				continue;
			continue;
		}
		while (getchar() != '\n')
			continue;
		for (i = 0; i < 4; i++)
		{
			if (fn == flight_code[i])
			{
				j = i;     //j 为航班班次 
				break;
			}
		}
		if (i == 4)
			continue;
		else
		{
			do
			{
				printf("Here is %d flight infomantion:\n", flight_code[j]);
				printf("To choose a function, enter its letter label:\n");
				printf("a) Show number of empty seats\n");
				puts("b) Show list of empty seats");
				puts("c) Show alphabetical list of seats");
				puts("d) Assign a customer to a seat assignment");
				puts("e) Ackonwleding assignment");
				puts("f) Delete a seat assignment");
				puts("g) Quit");
				ch = get_first();
				switch(ch) 
				{
					case 'a' : pf = empty_n; break;
					case 'b' : pf = show_empty; break;
					case 'c' : pf = show_alpha; break;
					case 'd' : pf = assign; break;
					case 'e' : pf = ak_assign_seat; break;
					case 'f' : pf = del; break;
					case 'g' : break;
					default  :puts("Please enter a correct choice.");
				}	
				
				if (ch >= 'a' && ch <= 'f')
					(*pf)(flight_info[j].seat_info, SEATS);
			
			}while (ch != 'g');
		}
		puts("Press y to continue, n to quit.");
		ch = get_first();
	} while (ch != 'n');
	
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
	printf("There are %d empty seats.\n", tot);
	return 0;
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
			if (toupper(ch) == ps[i].num)
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

int ak_assign_seat(struct seat * ps, int n)   //确认分配座位 
{
	int ch;
	for (int i = 0; i < n; i++)
	{
		if (ps[i].flag == 0)
		{
			printf("编号：%c empty\n\n", ps[i].num);
			printf("Press key y to take it, or press key n to choose yourself.\n"); 
			ch = get_first();
			if (ch == 'y')
			{
				printf("Enter you name:");
				scanf("%s%s", &ps[i].fname, &ps[i].lname);
				ps[i].flag = 1;
				puts("Assignment done!");
				break;
			}
			else
			{
				show_empty(ps, n);
				assign(ps, n);
				break;
			}
		}
	}
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
