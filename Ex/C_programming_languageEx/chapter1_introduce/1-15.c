/* Date��2020/3/23
 * 1-15����д1.2�����¶�ת������ʹ�ú���ʵ���¶�ת������
 */ 
 
#include <stdio.h> 
float fahr_to_cel(int fahr);	/* ����ԭ������ */
int main(void)
{
	float fahr;
	int lower = 0, upper = 300, step = 20;
	
	fahr = lower;
	printf("�����뻪���¶�ת����\n");
	printf("------------------------------\n");
	printf("����	����\n"); 
	while (fahr <= upper)
	{
		printf("%3.0f	%6.1f\n", fahr, fahr_to_cel(fahr));
		fahr += step;
	}
	return 0;
} 

float fahr_to_cel(int fahr) 
{
	return 5.0 / 9.0 * (fahr - 32);
}
