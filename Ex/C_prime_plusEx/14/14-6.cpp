# include <stdio.h> 
# include <stdlib.h>
# include <string.h>   //为memset提供原型 
# define NAMELEN 20
# define P_NUM 2
void show_ar(const struct player * ps, int n);
void get_info(struct player * ps) ;
void cal_bat_avg(struct player * ps, int n);

struct name {
	char fname[NAMELEN];
	char lname[NAMELEN];
};
struct player {
	int num;             //球员编号 
	struct name playername;    //球员姓名 
	int action_times;    //上场次数 
	int hit_times;   // 击中数 
	int out_times;    //走垒数    
	int rbi;      //打点 
	float bat_avg;   //安打率 
};

int main(void)
{
	struct player players[P_NUM];
	memset(&players, 0, P_NUM * sizeof(struct player));   //用memset()初始化结构数组为0 
	get_info(players);
	cal_bat_avg(players, P_NUM);
	show_ar(players, P_NUM);
	return 0;
}

void get_info(struct player * ps) 
{
	FILE * fp;
	int i, index = 0;
	struct player tmp;
	char filename[81];
	
	printf("Enter the filename：");
	scanf("%s", filename);
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Error, cant open file %s\n", filename);
		exit(1);
	}
	while (fscanf(fp, "%d", &tmp.num) == 1)
	{
		fscanf(fp, "%s", &tmp.playername.fname);
		fscanf(fp, "%s", &tmp.playername.lname);
		fscanf(fp, "%d", &tmp.action_times);
		fscanf(fp, "%d", &tmp.hit_times);
		fscanf(fp, "%d", &tmp.out_times);
		fscanf(fp, "%d", &tmp.rbi);
//		while(getc(fp) != '\n')
//			continue;
		
		for (i = 0; i < P_NUM; i++)
		{
			if (tmp.num == ps[i].num)
				break;
		}
		if (i == P_NUM)
			ps[index++] = tmp;
		else
		{
			ps[i].action_times += tmp.action_times;
			ps[i].hit_times += tmp.hit_times;
			ps[i].out_times += tmp.out_times;
			ps[i].rbi += tmp.rbi;
		}
	}
	if (fclose(fp) != 0)
		printf("File %s cant close\n", filename);
}

void show_ar(const struct player * ps, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Player number: %d\nPlayer name: %s %s\n", ps[i].num, ps[i].playername.fname, ps[i].playername.lname);
		printf("Action times: %d\nHit times: %d\nOutside times: %d\nRBI: %d\nBatting average: %.2f\n\n",
		ps[i].action_times, ps[i].hit_times, ps[i].out_times, ps[i].rbi, ps[i].bat_avg);
	}
}

void cal_bat_avg(struct player * ps, int n)
{
	for (int i = 0; i < n; i++)
		ps[i].bat_avg = ((float)ps[i].hit_times / ps[i].action_times);  //强制类型转换须放在里面 
}
