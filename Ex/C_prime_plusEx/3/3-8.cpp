# include <stdio.h>
int main(void)
{
	float cup;  //��Ϊ��������ΪС�� 
	
	scanf("%f", &cup);
	printf("%f �� = %f Ʒ��\n", cup, cup / 2);
	printf("%f �� = %f ��˾\n", cup, cup * 8);
	printf("%f �� = %f ������\n", cup, cup * 8 * 2);
	printf("%f �� = %f ����\n", cup, cup * 8 * 2 * 3);
	
	return 0; 
	
}
