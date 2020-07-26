# include <stdio.h> 
void show_info_a(const struct info * ps);
void show_info_b( const struct info detail);

# define LEN 40
struct name {
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

struct info {
	char insur[10];
	struct name names;
};

int main(void)
{
	struct info citizen[5] = {
		{"302039823", {"liangquan", "Manu", "guo"}},
		{"324324234", {"xioahua", "Had", "wang"}},
		{"324125454", {"dachui", "Bdf", "cao"}},
		{"325435456", {"fei", "Jan", "liu"}},
		{"376768887", {"shui", "Yun", "huang"}},   //内部都是逗号 
	};
	
	printf("Here is approach a:\n");
	show_info_a(citizen);
	printf("Here is approach b:\n");
	for (int i = 0; i < 5; i++)
		show_info_b(citizen[i]);
	return 0;
}

void show_info_a(const struct info * ps)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s, %s ", ps[i].names.fname, ps[i].names.lname);
		if(ps[i].names.mname[0] == '\0')
			printf("%c -- %s\n", ps[i].names.mname[0], ps[i].insur);
		else
			printf("%c. -- %s\n", ps[i].names.mname[0], ps[i].insur);
	}
}

void show_info_b( const struct info detail)  
{
	printf("%s, %s ", detail.names.fname, detail.names.lname);
	if (detail.names.mname[0] == '\0')
		printf("%c -- %s\n", detail.names.mname[0], detail.insur);
	else
		printf("%c. -- %s\n", detail.names.mname[0], detail.insur);
}
