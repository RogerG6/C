/* Date��2020/2/11 
 * ��д����squeeze(s1, s2): 
 *		�ַ���s1���ַ���s2��ͬ�±���ַ���ͬ�Ļ�����ɾ��s1����Ӧ���ַ� 
 */
 
#include <stdio.h>

int main(void)
{
	char s1[100], s2[100];
	int i, j;
	
	
	while (1)
	{
		printf("������s1��");
		gets(s1);
		printf("������s2��");
		gets(s2);
		
		i = j = 0;
		while(1)
		{
			/* ������������������iָ���ֵ����jָ���ֵ */ 
			if (s1[i] != s2[i])
			{
				s1[j] = s1[i];
				j++; 
			}
			i++;
			
			/* s2���ȴ��ڵ���s1 */ 
			if (s1[i] == '\0')
			{	
				s1[j] = '\0';
				break;
			}
		
			/* s2����С��s1 */ 
			if (s2[i] == '\0')
			{
				while ((s1[j++] = s1[i++]) != '\0');
				break;
			}
		}
		
		printf("ȥ�غ�\ns1: %s\ns2: %s\n", s1, s2)	;
			
	}
		
	return 0;
}
 
