struct
	�ṹ������struct book {
				char title[LEN];
				char author[LEN];
				float value;
			}; 
	�����ṹ����/���飺struct book library; 
					   struct {
					     char title[LEN];
					   	 char author[LEN];
					  	 float value;
					   }library; 
					   struct book library[LEN];
	��ʼ����struct book library = {
							"��������",
							"�޹���" ,
							45
						};
			struct book library = {
							.title = "��������",
							.author = "�޹���" ,
							.value = 45
						};
	���ʳ�Ա��1) library.author 
			  2) struct book * ptf;
			  	 ptf = &library;    �����鲻ͬ���ṹ�����ǽṹ�ĵ�ַ 
			  	 ptf->author;
	�������ݣ� ���ݽṹ�壺void function(struct book library) ;
  			   ���ݽṹ���ַ(����ָ������)��void function(struct book * ptf) ;
			   ���ݽṹ���Ա ��void function(char title);
	�������ԣ������鲻ͬ����ͬ�ṹ�����໥��ֵ 
union��һ���������ͣ��ͽṹ���ƣ�����union��ͬһʱ��㣬ͬһ�ڴ���ֻ�ܱ�ʾһ������ 
		union hold {
			int digit;
			double bigfl;
			char letter;
		}; 
		
typedef��ʹ��typedef֮ǰ ��unsigned char x, y[10], * z;
		 ʹ��typedef֮�� ��typedef unsigned char BYTE;
						   BYTE x, y[10], * z; 
enum��enum color {red, orange, yellow, green, blue, violet}; 
	  color: ����� 
	  red: ö�ٷ� 
�������� ��
		����ʹ�õķ��ţ�*	��ʾһ��ָ��	
					    ()	��ʾһ������ 
					    []	��ʾһ������
		���ȼ���()[]  >   *		
		����ɣ�()[]	��������
ָ������ָ��(�³ƺ���ָ��)����������ƣ�����Ҳ�е�ַ����Ϊ�����Ļ�������ʵ��������Ĵ�����ɣ�ָ������ָ���д����ź���������ʼ���ĵ�ַ��
		void toupper(char *);
		��������ָ�룺void (* pf)(char *);
		pf = toupper;   �����ĵ�ַ���Ǻ����� 
 
