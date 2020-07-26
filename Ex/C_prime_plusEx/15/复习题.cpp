1.  a. 11
	b. 1101
	c. 111011
	d. 1110111
2.    十进制	八进制	十六进制
	a. 21		25		15
	b. 85		125		55 
	c. 76		114		4C 
	d. 157		235		9D
3.  a. 11111100
	b. 00000010
	c. 00000111
	d. 00000111
	e. 00000101
	f. 00000011
	g. 00011100
4.  a. 11111111
	b. 00000001
	c. 00000000
	d. 00000001
	e. 00000110
	f. 00000001
	g. 00101000
5.  二进制        十进制	八进制	十六进制
	01111111		127		177		7F
6.  *=2 等同 <<=1	 
	+= 不等同 |=	因为后者是加上2的n次，前者仅仅是加一
7.  a. struct Tinkerbell {
				unsigned int soft_drive_num: 2;
				unsigned int : 1;
				unsigned int cd_drive_num: 2;
				unsigned int : 1;
				unsigned int hard_drive_num: 2;
		}
	b. struct Klinkerbell {
				unsigned int hard_drive_num: 2;
				unsigned int : 1;
				unsigned int cd_drive_num: 2;
				unsigned int : 1;
				unsigned int soft_drive_num: 2; 
		}
