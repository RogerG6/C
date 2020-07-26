# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	FILE * fp;
	char name[81];
	int int_arr[20][30];
	char char_arr[20][31];
	const char * syb = " .':~*=&%#";  //巧妙运用字符数组 
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
			
	for (int i = 0; i < 20; i++)  //初始化char数组 
	{
		for (int j = 0; j < 30; j++)
		{
			char_arr[i][j] = syb[int_arr[i][j]];
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
