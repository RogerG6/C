C预处理器
	# define
		类对象宏：# define PX printf("x is %d.\n", x) 
						   宏		替换体
		类函数宏：# define MEAN(X, Y) (((X) + (Y)) /2)
						   宏  宏参数       替换体
		#运算符
		##运算符 
		变参宏：...和__VA_ARGS__
			# define PR... printf(__VA_ARGS__)  省略号只能代替最后的宏参数 
	# include	替换源文件中的#include指令，相当于把被包含文件的全部内容输入到源文件#include所在的位置
	# undef		取消已定义的#define指令
		# define LIMIT 400
		# undef LIMIT
	条件编译 
	# ifdef		# else：# endif	旧的编译器不支持缩进 
		# ifdef MAVIS
			# include "horse.h"
			# define STABLES 5
		# else
			# include "cow.h"
			# define STABLES 15
		# endif  //必须存在 
	# ifndef 	# endif	：# ifndef用于判断后面的标识符是否是未定义的
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
	预定义宏
		__DATE__ 	预处理的日期 
		__FILE__	当前源代码文件名的字面量 
		__LINE__	当前源代码文件中行号的整型常量 
		__STDC__	设置为1时，表明实现遵循C标准 
		__STDC_HOSTED__		本机环境设置为1；否则设置为0 
		__STDC_VERSION__	支持C99标准，设置为199901L；支持C11标准，设置为201112L 
		__TIME__ 	翻译代码的时间 
	# line	用于重置__LINE__和__FILE__宏报告的行号和文件名 
		# line 1000		当前行号重置为1000 
		# line 10 "cool.c" 		当前行号重置为10，当前文件名重置为cool.c 
	# error		让编译器发出一条错误消息，该消息中包含指令中的文本。若可能，编译过程应中断
		# if __STDC_VERSION__ != 201112L
		# error Not C11
		#endif 
	# pragma(编译指示)	把编译器指令放入源代码中
		#pragma c9x on	//让编译器支持C9X 
	泛型选择（C11） 
		泛型编程：指那些没有特定类型，然后编译器根据指定一种类型，就可以转换成指定类型的代码
		泛型选择表达式(C中没有泛型算法，但有泛型选择表达式) 
			# define MYTYPE(X) _Generic((X), int: "int", float: "float", double: "double", default: "other") 
	内联函数(c99) ：如果把函数变成内联函数，编译器可能会用内联代码替换函数调用，并(或) 执行一些其他的优化，但也可能不起作用，具体效果由实现定义 
		# include <stdio.h> 
		inline static void eatline()   //内联函数定义 
		{
			while (getchar() != '\n')
				continue;
		}
		int main(void)
		{
			...
			eatline();   //函数调用，相当于在调用位置输入函数体代码 
			...
		}
		优点：因为函数的调用过程包括建立调用、传递参数、跳转至函数并返回。而使用宏使代码内联，可以避免这样的开销。
			  适用于小函数
	Noreturn 函数：表明调用完成后，函数不返回主调函数 
C库
	访问C库的3种途径
		1、自动访问
		2、文件包含
		3、库包含
	math.h库 
	tgmath.h库 
	通用工具库
		exit() 和 atexit() 
			atexit()：参数是函数地址，atexit() 注册列表中的函数个数最多为32个，且最后添加最先执行 
				atexit(eatline) ;
			exit()：会完成一些清理工作: 刷新所有输出流、关闭所有打开的流和关闭由标准IO函数tmpfile()创建的临时文件。 
					然后将控制权返回主机环境，若可能，向主机报告终止状态。 
					main()结束时会隐性调用exit() 
		qsort() 
			原型：void qsort(void * base, size_t nmemb, size_t size, int (* compar)(const void *, const void *))
	断言库
		assert.h
		_Static_assert
	string.h库中的memcpy() 和memmove() 
	可变参数：stdarg.h 
		int f2(const char * s, int k, ...);
			    			   parmN: 传递给该参数的实参是省略号代表的参数数量
		用法：
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
				va_list ap;    //声明一个对象储存参数 
				double tot = 0;
				
				va_start(ap, lim);  //把ap初始化为参数列表 
				for (int i = 0; i < lim; i++)
					tot += va_arg(ap, double);  //访问参数中的每一项，double代表变量类型 
				va_end(ap);   //清理工作 
				
				return tot;
			}
			
			
	 
