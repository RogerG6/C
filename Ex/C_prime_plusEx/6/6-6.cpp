# include <stdio.h>

int main(void)
{
	int low, up, i;
	
	printf("���������޺����ޣ�"); 
	scanf("%d %d", &low, &up);
	printf("��ֵ         ƽ��           ����\n");
	for (i = low; i <= up; i++)
		printf("%2d        %5d        %8d\n", i, i*i, i*i*i);
	
	return 0;
	
}
