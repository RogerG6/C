# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define colum 30
void dis_eli(int st[][30], int row);

int main(void)
{
	FILE * fp;
	char name[81];
	int int_arr[20][30];
	char char_arr[20][31];
	int bytes;
	
	printf("Enter the file name:");
	scanf("%s", name);
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Cant open %s\n", name);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 20; i++)   //初始化int数组 
		for (int j = 0; j < 30; j++)
			fscanf(fp, "%d", &int_arr[i][j]);
			
	dis_eli(int_arr, 20);
			
	for (int i = 0; i < 20; i++)  //初始化char数组 
	{
		for (int j = 0; j < 30; j++)
		{
			bytes = int_arr[i] [j];
			switch(bytes)
			{
				case 0: char_arr[i] [j] = ' '; break;
				case 1: char_arr[i] [j] = '.'; break;
				case 2: char_arr[i] [j] = 39 ; break;
				case 3: char_arr[i] [j] = ':'; break;
				case 4: char_arr[i] [j] = '~'; break;
				case 5: char_arr[i] [j] = '*'; break;
				case 6: char_arr[i] [j] = '='; break;
				case 7: char_arr[i] [j] = '&'; break;
				case 8: char_arr[i] [j] = '%'; break;
				case 9: char_arr[i] [j] = '#'; break;
			}
		}
		char_arr[i][30] = '\0';
	}
	
	for (int i = 0; i < 20; i++)    //显示char数组 
	{
			for (int j = 0; j < 30; j++)
		{
			fprintf(stdout, "%c", char_arr[i][j]);
		}
		putchar('\n');
	}
		
	
	return 0;
}

void dis_eli(int st[][30], int row)   //消除失真  distortion elimination 
{
	int r, c;
	for (int i = 0; i < row; i++)    //显示char数组 
	{
		for (int j = 0; j < colum; j++)
		{
			if ((0 == i && 0 == j) || (i == row -1 && j == 0) || (i == 0 && j == colum -1) || (i == row -1 && j == colum -1)) 
			{
				if (0 == i && 0 == j)
				{
					r = 1; c = 1;
				}
				else if (i == row -1 && j == 0)
				{
					r = -1; c = 1;
				}
				else if (i == 0 && j == colum -1)
				{
					r = 1; c = -1;
				}
				else
				{
					r = -1; c = -1;
				}
				if(abs(st[i][j+c] - st[i][j]) > 1 && abs(st[i+r][j] - st[i][j]) > 1) 
				{
					if (((st[i][j+c] + st[i+r][j]) % 2) / 2.0 >= 0.5)
						st[i][j] = ((st[i][j+c] + st[i+r][j] )/ 2) + 1;
					else
						st[i][j] = (st[i][j+c] + st[i+r][j] )/ 2;
				}
			}
			else if ((i == 0 && j > 0) || (i > 0 && j == 0) || (i == row -1 && j > 0) || (i > 0 && j == colum -1))
			{
				if (i == 0 && j > 0)
				{
					if (abs(st[i][j+1] - st[i][j]) > 1 && abs(st[i][j-1] - st[i][j]) > 1 && abs(st[i+1][j] - st[i][j]) > 1)
					{
						if (((st[i][j-1] + st[i][j+1] + st[i+1][j]) % 3) / 3.0 >= 0.5)
							st[i][j] = ((st[i][j-1] + st[i][j+1] + st[i+1][j]) / 3)+ 1;
						else
							st[i][j] = (st[i][j-1] + st[i][j+1] + st[i+1][j] )/ 3;
					}
				}
				else if (i > 0 && j == 0)
				{
					if (abs(st[i][j+1] - st[i][j]) > 1 && abs(st[i+1][j] - st[i][j]) > 1 && abs(st[i-1][j] - st[i][j]) > 1)
					{
						if (((st[i][j+1] + st[i+1][j] + st[i-1][j]) % 3) / 3.0 >= 0.5)
							st[i][j] = ((st[i][j+1] + st[i+1][j] + st[i-1][j]) / 3)+ 1;
						else
							st[i][j] = (st[i][j+1] + st[i+1][j] + st[i-1][j]) / 3;
					}
				}
				else if (i == row -1 && j > 0)
				{
					if (abs(st[i][j+1] - st[i][j]) > 1 && abs(st[i][j-1] - st[i][j]) > 1 && abs(st[i-1][j] - st[i][j]) > 1)
					{
						if (((st[i][j-1] + st[i][j+1] + st[i-1][j]) % 3) / 3.0 >= 0.5)
							st[i][j] =( (st[i][j-1] + st[i][j+1] + st[i-1][j]) / 3)+ 1;
						else
							st[i][j] = (st[i][j-1] + st[i][j+1] + st[i-1][j]) / 3;
					}	
				}
				else
				{
					if (abs(st[i][j-1] - st[i][j]) > 1 && abs(st[i+1][j] - st[i][j]) > 1 && abs(st[i-1][j] - st[i][j]) > 1)
					{
						if (((st[i][j-1] + st[i+1][j] + st[i-1][j]) % 3) / 3.0 >= 0.5)
							st[i][j] =( (st[i][j-1] + st[i+1][j] + st[i-1][j]) / 3)+ 1;
						else
							st[i][j] = (st[i][j-1] + st[i+1][j] + st[i-1][j]) / 3;
					}
				}
			}
			else
			{
				if (abs(st[i][j+1] - st[i][j]) > 1 && abs(st[i][j-1] - st[i][j]) > 1 && abs(st[i+1][j] - st[i][j]) > 1 && abs(st[i-1][j] - st[i][j]) > 1)
				{
					if (((st[i][j+1] + st[i][j-1] + st[i+1][j] + st[i-1][j]) % 4) / 4.0 >= 0.5)
						st[i][j] = ((st[i][j+1] + st[i][j-1] + st[i+1][j] + st[i-1][j]) / 4) + 1;
					else
						st[i][j] = (st[i][j+1] + st[i][j-1] + st[i+1][j] + st[i-1][j]) / 4;
				}
			}	
		}
	}
}
