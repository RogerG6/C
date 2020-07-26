1.  自动变量	寄存器存储类别	形参	静态、无链接
2.  静态变量
3.  静态变量、外部链接	静态变量、内部链接
4.  无链接属性
5.  引用式声明， 表明该变量或函数已在别处定义
6.  第二行calloc把数组每个元素设置为0 
7.	文件1   
	daisy：文件1、2
	lily：main()可见，petal中的lily有误，文件2中的lily仅该文件可见
	文件2
	rose：文件2可见，stem()中的rose会覆盖外部的rose
8.  color in main() is B
	color in first() is R
	color in main()	is B
	color in second() is G
	color in main() is G
9.  a.声明了plink的静态变量，内部链接
	  形参arr[]指向的数组中的数据限定为可读
	b.不会，因为value、n都已经是主调函数数据的备份 
