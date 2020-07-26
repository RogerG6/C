# include <stdio.h> 
void get_name(struct student * ps);
void get_grade(struct student *ps);
float comp_avg(struct student * ps);
void show_info(struct student * ps);

# define LEN 40
# define CSIZE 4
//a
struct name {
	char fname[LEN];
	char lname[LEN];
};

//b
struct student {
	struct name s_name;
	float score[3];
	float avg;
};

//c
int main(void)
{
	float class_avg;
	struct student students[CSIZE] ;
	
	get_name(students);
	get_grade(students);
	class_avg = comp_avg(students);
	show_info(students);
	printf("Average of class: %f\n", class_avg);
	
	return 0;
}

void get_name(struct student * ps)
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Enter students' names:\n");
		scanf("%s%s", ps[i].s_name.fname, ps[i].s_name.lname);
//		while (getchar() != '\n')
//			continue;
	}
}

void get_grade(struct student *ps)
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Enter students' grades:\n");
		scanf("%f%f%f", &ps[i].score[0], &ps[i].score[1], &ps[i].score[2]);  //d
	//	printf("%f\n", ps[i].score[1]);
//		while (getchar() != '\n')
//			continue;
	}
}

float comp_avg(struct student * ps)
{
	float class_avg = 0;
	for (int i = 0; i < CSIZE; i++)
	{
		ps[i].avg =  (ps[i].score[0] + ps[i].score[1] + ps[i].score[2]) / 3;
		class_avg += ps[i].avg;
	}
	class_avg = class_avg / CSIZE;
	return class_avg;     //g
}

void show_info(struct student * ps)  //f
{
	for (int i = 0; i < CSIZE; i++)
	{
		printf("Name: %s %s\n", ps[i].s_name.fname, ps[i].s_name.lname);
		printf("Grade: %.2f %.2f %.2f\n", ps[i].score[0], ps[i].score[1], ps[i].score[2]);
		printf("Average: %.2f\n", ps[i].avg);
		putchar('\n');
	}
}
