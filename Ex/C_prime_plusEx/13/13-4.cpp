//�����ʾ�����в������ļ����� 
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * fp;
//	int c;
	char tmp[1024];
	
	for (int i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "rb")) == NULL)
		{
			printf("Cant open %s", argv[i]);
			continue;
		}
	//	while ((c = getc(fp)) != EOF)   //����ַ���ȡ��ʾ���ٶ������е㿨 
	//		putc(c, stdout);
		while (fgets(tmp, 1024, fp) != NULL)   //��ȡ�ַ�������ʾ�ٶȿ� 
			fputs(tmp, stdout);
	}
	
	return 0;
}
