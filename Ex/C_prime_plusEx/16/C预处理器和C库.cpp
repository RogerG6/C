CԤ������
	# define
		�����꣺# define PX printf("x is %d.\n", x) 
						   ��		�滻��
		�ຯ���꣺# define MEAN(X, Y) (((X) + (Y)) /2)
						   ��  �����       �滻��
		#�����
		##����� 
		��κ꣺...��__VA_ARGS__
			# define PR... printf(__VA_ARGS__)  ʡ�Ժ�ֻ�ܴ������ĺ���� 
	# include	�滻Դ�ļ��е�#includeָ��൱�ڰѱ������ļ���ȫ���������뵽Դ�ļ�#include���ڵ�λ��
	# undef		ȡ���Ѷ����#defineָ��
		# define LIMIT 400
		# undef LIMIT
	�������� 
	# ifdef		# else��# endif	�ɵı�������֧������ 
		# ifdef MAVIS
			# include "horse.h"
			# define STABLES 5
		# else
			# include "cow.h"
			# define STABLES 15
		# endif  //������� 
	# ifndef 	# endif	��# ifndef�����жϺ���ı�ʶ���Ƿ���δ�����
		# ifndef SIZE
			# define SIZE 100
		# endif 
	# if	# elif		#endif
		# if SYS == 1 
			# include "ibmpc.h" 
		# elif SYS == 2
			# include "vax.h"
		# elif SYS == 3
			# include "mac.h"
		# else
			# include "general.h"
		# endif
	Ԥ�����
		__DATE__ 	Ԥ��������� 
		__FILE__	��ǰԴ�����ļ����������� 
		__LINE__	��ǰԴ�����ļ����кŵ����ͳ��� 
		__STDC__	����Ϊ1ʱ������ʵ����ѭC��׼ 
		__STDC_HOSTED__		������������Ϊ1����������Ϊ0 
		__STDC_VERSION__	֧��C99��׼������Ϊ199901L��֧��C11��׼������Ϊ201112L 
		__TIME__ 	��������ʱ�� 
	# line	��������__LINE__��__FILE__�걨����кź��ļ��� 
		# line 1000		��ǰ�к�����Ϊ1000 
		# line 10 "cool.c" 		��ǰ�к�����Ϊ10����ǰ�ļ�������Ϊcool.c 
	# error		�ñ���������һ��������Ϣ������Ϣ�а���ָ���е��ı��������ܣ��������Ӧ�ж�
		# if __STDC_VERSION__ != 201112L
		# error Not C11
		#endif 
	# pragma(����ָʾ)	�ѱ�����ָ�����Դ������
		#pragma c9x on	//�ñ�����֧��C9X 
	����ѡ��C11�� 
		���ͱ�̣�ָ��Щû���ض����ͣ�Ȼ�����������ָ��һ�����ͣ��Ϳ���ת����ָ�����͵Ĵ���
		����ѡ����ʽ(C��û�з����㷨�����з���ѡ����ʽ) 
			# define MYTYPE(X) _Generic((X), int: "int", float: "float", double: "double", default: "other") 
	��������(c99) ������Ѻ�������������������������ܻ������������滻�������ã���(��) ִ��һЩ�������Ż�����Ҳ���ܲ������ã�����Ч����ʵ�ֶ��� 
		# include <stdio.h> 
		inline static void eatline()   //������������ 
		{
			while (getchar() != '\n')
				continue;
		}
		int main(void)
		{
			...
			eatline();   //�������ã��൱���ڵ���λ�����뺯������� 
			...
		}
		�ŵ㣺��Ϊ�����ĵ��ù��̰����������á����ݲ�������ת�����������ء���ʹ�ú�ʹ�������������Ա��������Ŀ�����
			  ������С����
	Noreturn ����������������ɺ󣬺����������������� 
C��
	����C���3��;��
		1���Զ�����
		2���ļ�����
		3�������
	math.h�� 
	tgmath.h�� 
	ͨ�ù��߿�
		exit() �� atexit() 
			atexit()�������Ǻ�����ַ��atexit() ע���б��еĺ����������Ϊ32����������������ִ�� 
				atexit(eatline) ;
			exit()�������һЩ������: ˢ��������������ر����д򿪵����͹ر��ɱ�׼IO����tmpfile()��������ʱ�ļ��� 
					Ȼ�󽫿���Ȩ�������������������ܣ�������������ֹ״̬�� 
					main()����ʱ�����Ե���exit() 
		qsort() 
			ԭ�ͣ�void qsort(void * base, size_t nmemb, size_t size, int (* compar)(const void *, const void *))
	���Կ�
		assert.h
		_Static_assert
	string.h���е�memcpy() ��memmove() 
	�ɱ������stdarg.h 
		int f2(const char * s, int k, ...);
			    			   parmN: ���ݸ��ò�����ʵ����ʡ�ԺŴ���Ĳ�������
		�÷���
			# include <stdio.h>
			# include <stdarg.h>
			double sum(int, ...);
			int main(void)
			{
				double s;
				s = sum(3, 1.1, 2.2, 3.3);
				return 0;
			}
			double sum(int lim, ...)
			{
				va_list ap;    //����һ�����󴢴���� 
				double tot = 0;
				
				va_start(ap, lim);  //��ap��ʼ��Ϊ�����б� 
				for (int i = 0; i < lim; i++)
					tot += va_arg(ap, double);  //���ʲ����е�ÿһ�double����������� 
				va_end(ap);   //������ 
				
				return tot;
			}
			
			
	 
