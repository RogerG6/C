# include <stdio.h>
# include "pe12-3a.h"

int main(void)
{
	int mode, pre;
	double dis, fuel;
	
	printf("Enter 0 for metric mode, 1 for US mode:");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(&pre, mode);
		get_info(&dis, &fuel, pre);
		show_info(dis, fuel, pre);
		printf("Enter 0 for metric mode, 1 for US mode(-1 to quit)");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	
	return 0;
}
