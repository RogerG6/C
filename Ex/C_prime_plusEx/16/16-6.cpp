# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int mycomp(const void * p1, const void * p2);
void show(struct names * ps, int n);

struct names{
	char first[40];
	char last[40];
};
int main(void)
{
	struct names grade[3] = {{"James", "bode"}, {"kirk", "Halen"}, {"alin", "five"}};
	
	qsort(grade, 3, sizeof(struct names), mycomp);
	show(grade, 3);
	return 0;
}

void show(struct names * ps, int n)
{
	for (int i = 0; i < n; i++)
		printf("%s %s\n", ps[i].first, ps[i].last);
}

int mycomp(const void * p1, const void * p2)
{
	const struct names * ps1 = (const struct names *)p1;
	const struct names * ps2 = (const struct names *)p2;
	
	int res;
	res = strcmp(ps1->last, ps2->last);
	if (res != 0)
		return -res;
	else
		return strcmp(ps1->first, ps2->first);
}
