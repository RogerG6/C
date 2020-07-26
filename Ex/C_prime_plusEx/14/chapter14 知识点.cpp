struct
	结构声明：struct book {
				char title[LEN];
				char author[LEN];
				float value;
			}; 
	声明结构变量/数组：struct book library; 
					   struct {
					     char title[LEN];
					   	 char author[LEN];
					  	 float value;
					   }library; 
					   struct book library[LEN];
	初始化：struct book library = {
							"三国演义",
							"罗贯中" ,
							45
						};
			struct book library = {
							.title = "三国演义",
							.author = "罗贯中" ,
							.value = 45
						};
	访问成员：1) library.author 
			  2) struct book * ptf;
			  	 ptf = &library;    与数组不同，结构名不是结构的地址 
			  	 ptf->author;
	参数传递： 传递结构体：void function(struct book library) ;
  			   传递结构体地址(巧用指针数组)：void function(struct book * ptf) ;
			   传递结构体成员 ：void function(char title);
	其他特性：与数组不同，相同结构间能相互赋值 
union：一种数据类型，和结构类似，但是union在同一时间点，同一内存中只能表示一种数据 
		union hold {
			int digit;
			double bigfl;
			char letter;
		}; 
		
typedef：使用typedef之前 ：unsigned char x, y[10], * z;
		 使用typedef之后 ：typedef unsigned char BYTE;
						   BYTE x, y[10], * z; 
enum：enum color {red, orange, yellow, green, blue, violet}; 
	  color: 标记名 
	  red: 枚举符 
复杂声明 ：
		声明使用的符号：*	表示一个指针	
					    ()	表示一个函数 
					    []	表示一个数组
		优先级：()[]  >   *		
		结合律：()[]	从左往右
指向函数的指针(下称函数指针)：与变量类似，函数也有地址，因为函数的机器语言实现由载入的代码组成，指向函数的指针中储存着函数代码起始处的地址。
		void toupper(char *);
		声明函数指针：void (* pf)(char *);
		pf = toupper;   函数的地址就是函数名 
 
