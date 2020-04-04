
calc: test_infix.o stack.o infix_to_suffix.o 
	gcc -o test  stack.o test_infix.o infix_to_suffix.o  
test_infix:test_infix.c
	gcc -c  test_infix.c
	
infix_to_suffix.o:infix_to_suffix.c
	gcc -c infix_to_suffix.c
stack.o:stack.c
	gcc -c stack.c
