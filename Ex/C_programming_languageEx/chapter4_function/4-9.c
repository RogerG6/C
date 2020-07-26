 /* Date: 2020/2/17
  * 4-9：以上介绍的getch与ungetch函数不能正确地处理压回的EOF。考虑压回EOF时应该如何处理？请实现你的设计方案
  */ 
  
/*
将之前的 char buf[BUFSIZE]; 
改成     int buf[BUFSIZE]; 

原因：
	当char转换成int时，有2种可能，下面以值-1为例：
	负数(-1)    ->		char		->		int 
	0xFFFF				0xFF				0X00FF(255)
	0XFFFF				0XFF				0XFFFF(-1)
	
	而EOF(-1)在不同的机器上转换时，很有可能转换成与我们目标不符的值
	
	因此最好用  int buf[BUFSIZE]; 
	
*/ 
