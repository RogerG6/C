# include <stdio.h>
# define A_PRICE 2.05
# define B_PRICE 1.15
# define C_PRICE 1.09
# define DISCOUNT 0.05
# define D_P 100 //discount price
# define W_BREAK1 5  //weight break
# define W_BREAK2 20
# define C_F1 6.5
# define C_F2 14
# define C_F_CONTINUE 0.5 //���ص��� 

int main(void)
{
	float a_w;
	float b_w;
	float c_w;
	float all_w;  //a_w=a weight
	float c_f, a_f, fare; //dt=discount, c_f=carriage fare, a_p=all fare
	float dt;
	char ch; 
	
	while(1)
	{
		a_w = 0;
		b_w = 0;
		c_w = 0;
		all_w = 0;  //a_w=a weight
		c_f= 0, a_f = 0, fare = 0; //dt=discount, c_f=carriage fare, a_p=all fare
		dt = 0;
		printf("a = �󼻣� b = ��ˣ� c = ���ܲ��� q = quit\n");
		do
		{
			printf("��������Ӧ����ĸѡ��: ");
			scanf( " %c", &ch);  //�˴�%cǰ����ӿո� 
				switch (ch)
				{
					case 'a': printf("�������󼻵İ�����");
							  scanf("%f", &a_w);
							  break;
					case 'b': printf("��������˵İ�����");
							  scanf("%f", &b_w);
							  break;
					case 'c': printf("��������ܲ��İ�����");
							  scanf("%f", &c_w);
							  break;
					case 'q': break;
					default : printf("��������ȷ����ĸ��\n");
				}
		} while (ch != 'q' );
		printf("\n");
		
		a_f = A_PRICE * a_w + B_PRICE * b_w + C_PRICE * c_w;
		all_w = a_w + b_w + c_w;
		
		if (D_P <= a_f)
			dt = DISCOUNT * a_f;
		
		if(all_w <= W_BREAK1 && all_w > 0)
			c_f = C_F1;
		else if (all_w > W_BREAK1 && all_w <= W_BREAK2)
			c_f = C_F2;
		else if (all_w > W_BREAK2)
			c_f = C_F2 + (all_w - W_BREAK2) * C_F_CONTINUE;
			
		printf("���Ĺ�����Ϣ���£�\n");
		printf("--------------------------------------------------------------------------------");
		printf("����                    �ۼ�                    ����������\n");
		printf("��                    %2.2f                   %5.2f\n", A_PRICE, a_w);
		printf("���                    %2.2f                   %5.2f\n", B_PRICE, b_w);
		printf("���ܲ�                  %2.2f                   %5.2f\n", C_PRICE, c_w);
		printf("��������%.2f\n�����ܶ%.2f\n�ۿۣ�%.2f\n�˷ѣ�%.2f\n�����ܶ%.2f\n", all_w, a_f, dt, c_f, a_f - dt + c_f);
		printf("--------------------------------------------------------------------------------");	
	}
	
	return 0;	
}
