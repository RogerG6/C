1.  8 8
	4 4
	0 0
	2 2
	
2.  4

3.  ref的地址是&ref[0]  ref+1 是第二个元素的地址   ++ref无效，ref是常量 

4.  *ptr     *(ptr+2) 
a   12        16
b   12        14

5.  **ptr    **(pter+1)
a   12        16
b   12        14

6.  
a. &grid[22][56]  
b. &grid[22][0]
   grid[22]
c. &grid[0][0]
   (int *)grid
   grid[0]
   
7. 
a. int digits[10]
b. float rates[6]
c. int mat[3][5]
d. int * psa[20]
e. char (*pstr)[20]

8. 
a. int a[6] = {1, 2, 4, 8, 16, 32}
b. a[2] = 4;
c. int a[100] = {[99] = -1};
d. int a[100] = {[3] = 101, [5] = 101, [10] = 101, 101, 101};

9. 0-9

11. int a[800][600];

12. 
a. void f(double ar[], int);
   f(trots, 20);
b. void f(short ar[][30], int);
   f(clops, 10);
c. void f(long ar[][10][15], int );
   f(shots, 5);
   
13.
a. show((double []){8, 3, 9, 2}, 4);
b. show2((double [][3]){{8, 3, 9}, {5, 4, 1}}, 2);


   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
