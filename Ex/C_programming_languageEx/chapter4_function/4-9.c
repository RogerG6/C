 /* Date: 2020/2/17
  * 4-9�����Ͻ��ܵ�getch��ungetch����������ȷ�ش���ѹ�ص�EOF������ѹ��EOFʱӦ����δ�����ʵ�������Ʒ���
  */ 
  
/*
��֮ǰ�� char buf[BUFSIZE]; 
�ĳ�     int buf[BUFSIZE]; 

ԭ��
	��charת����intʱ����2�ֿ��ܣ�������ֵ-1Ϊ����
	����(-1)    ->		char		->		int 
	0xFFFF				0xFF				0X00FF(255)
	0XFFFF				0XFF				0XFFFF(-1)
	
	��EOF(-1)�ڲ�ͬ�Ļ�����ת��ʱ�����п���ת����������Ŀ�겻����ֵ
	
	��������  int buf[BUFSIZE]; 
	
*/ 
