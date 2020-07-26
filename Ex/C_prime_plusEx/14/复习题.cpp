1.  struct asd{char itable; int num[20]; char * togs; };
2.  6 1
	22 Spiffo Road 
	S p
3.  struct month{
		char name[10];
		char shortname[4];
		int days;
		int number;
	};
4.  struct month months[12] = {
		{"janury", "jan", 31, 1}, {"feburaly", "feb", 28, 2}, {"march", "mar", 31, 3}, {"april", "apr", 30, 4}, {"may", "may", 31, 5}, 
		{"june", "jun", 30, 6},{"july", "jul", 31, 7}, {"august", "aug", 31, 8}, {"septeber", "sep", 30, 9}, {"october", "oct", 31, 10}, 
		{"november", "nov", 30, 11}, {"deceber", "dec", 31, 12}
	};
5.  int days(int num)
	{
		int tot = 0;
		for (int i = 0; i < num; i++)
		{
			tot += months[i].days;
		}
		return tot;
	}
6.a.# include <string.h>
	LENS len[10];
	len[2].foclen = 500;
	len[2].fstop = 2.0;
	strcpy(len[2].brand, "Remarkata");
  b.LENS len[10] = { [2] = {500, 2.0, "Remarkata"}};
7.a. 6
	 Arcturan
	 cturan
  b. pb->title.last
  	 (*pb).title.last
  c. # include <stdio.h>
  	 # include "starfolk.h"
     void show(struct bem * p)
     {
     	printf("%s %s is a %d-limbed %s.", (*p).title.first, (*p).title.last, (*p).limbs, (*p).type);
	 }
8.a. willie.born
  b. pt->born
  c. scanf("%d", willie.born);
  d. scanf("%d", pt->born);
  e. scanf("%s", willie.name.lname);
  f.scanf("%s", pt->name.lname);
  g.willie.name.fname[2];
  h. strlen(willie.name.fname) + strlen(willie.name.lname);
9.struct car {
	char carname[10];
	float power;
	char statul[10];
	float zhouju;
	char date[10];
  }
10. a. struct gas mpg(struct gas car1)
       {
       		if (car1.gals > 0)
       			car1.mpg = car1.distance / car1.gals;
       		else
       			car1.mpg = -1.0;
       		return car1;
	   }
	b. float mpg(struct gas car1)
       {
       		if (car1.gals > 0)
       			car1.mpg = car1.distance / car1.gals;
       		else
       			ca1.mpg = -1.0;
       		return car1.mpg;
	   }
11. enum choice = {no, yes, maybe};
12. char * (* p) (char * pt, char ch);
13. double f1(double a, double b);
	double f2(double a, double b);
	double f3(double a, double b);
	double f4(double a, double b);
	
	double (* p[4])(double a, double b) = {f1, f2, f3, f4};

	(*p[1])(10.0, 2.5);
	p[1](10.0, 2.5);
