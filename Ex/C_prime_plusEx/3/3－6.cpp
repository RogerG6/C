# include <stdio.h>
int main(void)
{
	double mw = 3.0e-23;  //mwΪһ��ˮ���ӵ�����
	float quarts;
	
	scanf("%f", &quarts); 
	printf("һ����ˮ�� %le ��ˮ����\n", 950 * quarts / mw);
	
	return 0; 
}
