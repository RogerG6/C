/* Date��2020/3/4 
 * 4-12������printd���������˼���дһ���ݹ�汾��itoa��������ͨ���ݹ���ð�����ת�����ַ���
 */ 

#include <stdio.h>
#define abs(x) ((x > 0) ? (x) : (-x))


void itoa(char s[], int n)
{
	static int i;
	
	if (n / 10)
		itoa(s, n / 10);
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';		//֮ǰ��'\0' �ᱻ���� 
}

int main(void)
{
	int num;
	char a[100];
	
	printf("������һ��������");
	scanf("%d", &num);
	
	itoa(a, num);
	printf("%d ת�����ַ�����%s\n", num, a);
	
	
	return 0;
}
